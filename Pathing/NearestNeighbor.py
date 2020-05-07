# -*- coding: utf-8 -*-
"""
Created on Wed May  6 04:13:20 2020

@author: Michael
"""

import csv
import math

zoneList = list();
riserList = list();

class coordinate:
    def __init__(self,x_coord,y_coord):
        self.x = x_coord
        self.y = y_coord

class cRow:
    def __init__(self):
        self.color = "None"

class riser:
    def __init__(self, coord, color):
        self.color = color
        self.coord = coord
        self.tempStacked = False
        self.stacked = False

class zone:
    def __init__(self, coord):
        self.coord = coord
        self.stacked = False
        self.row = row
class path:
    def __init__(self, vector, distance, color):
        self.vector = vector
        self.distance = distance
        self.color = color

#load coordinate data from csv's 
with open('zoneCoordinate.csv', newline='') as csvfile:
    zoneCoordReader = csv.reader(csvfile, delimiter=',')
    for row in zoneCoordReader:
        zoneList.append(zone(coordinate(int(row[0])*6, int(row[1])*6)))
        

with open('riserCoordinate.csv', newline='') as csvfile:
    riserCoordReader = csv.reader(csvfile, delimiter= ',')
    for row in riserCoordReader:
        if(int(row[2]) == 0):
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Orange"))
        elif(int(row[2]) == 1):
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Purple"))
        else:
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Blue"))

row_1 = cRow()
row_2 = cRow()
row_3 = cRow()

zoneList[0].row = row_1
zoneList[1].row = row_1
zoneList[2].row = row_1

zoneList[3].row = row_2
zoneList[4].row = row_2
zoneList[5].row = row_2

zoneList[6].row = row_3
zoneList[7].row = row_3
zoneList[8].row = row_3

def dist(startCoord, endCoord):
    xdiff = endCoord.x - startCoord.x
    ydiff = endCoord.y - startCoord.y
    return int(math.sqrt(xdiff*xdiff + ydiff*ydiff) + 5)
            
def nearestRiser(startCoord):
    minIndex = 0;
    minDist = 2147483647;#largest positive integer in Python
    currIndex = 0;
    currDist = 0;
    for riser in riserList:
        if(riser.stacked == False):
            currDist = dist(riser.coord, startCoord)
            if(currDist < minDist):
                minIndex = currIndex
                minDist = currDist
        currIndex += 1   
    
    print(f'The nearest riser to the point {startCoord.x},{startCoord.y} is riser {minIndex+1} at {riserList[minIndex].coord.x},{riserList[minIndex].coord.y}')
    return minIndex, minDist
    
def nearestColor(startCoord, color):
    minIndex = 0;
    minDist = 2147483647;#largest positive integer in Python
    currIndex = 0;
    currDist = 0;
    for riser in riserList:
        if((riser.color == color) and (riser.stacked == False)):
            currDist = dist(riser.coord, startCoord)
            if(currDist < minDist):
                minIndex = currIndex
                minDist = currDist
        currIndex += 1   
    
    print(f'The nearest {color} riser to the point {startCoord.x},{startCoord.y} is riser {minIndex+1} at {riserList[minIndex].coord.x},{riserList[minIndex].coord.y}')
    return minIndex, minDist

def nearestZone(startCoord, color):
    minIndex = -1;
    minDist = 2147483647;#largest positive integer in Python
    currIndex = 0;
    currDist = 0;
    for zone in zoneList:
        if(zone.stacked == False and (zone.row.color == "None" or zone.row.color == color)):
            currDist = dist(zone.coord, startCoord)
            if(currDist < minDist):
                minIndex = currIndex
                minDist = currDist
        currIndex += 1 
        
    print(f'The nearest unstacked zone to the point {startCoord.x},{startCoord.y} is zone {minIndex+1} at {zoneList[minIndex].coord.x},{zoneList[minIndex].coord.x}')
    return minIndex, minDist
def unStackPath(path):
    length = len(path.vector)
    for i in range(0, length-1):
        riserList[path.vector[i]-1].stacked = False
        
def countStacked():
    count = 0
    for riser in riserList:
        if(riser.stacked):
            count+= 1
    return count
def pathThree(startCoord, color):
    pathVector = list()
    totalDistance = 0;
    lastIndex = 0
    tempDistance = 0;
    tempIndex = 0;
    
    tempIndex, tempDistance = nearestColor(startCoord, color)
    pathVector.append(tempIndex + 1)
    totalDistance += tempDistance
    lastIndex = tempIndex
    riserList[tempIndex].stacked = True
    
    tempIndex, tempDistance = nearestColor(riserList[lastIndex].coord,color)
    pathVector.append(tempIndex + 1)
    totalDistance += tempDistance
    lastIndex = tempIndex
    riserList[tempIndex].stacked = True
    
    tempIndex, tempDistance = nearestColor(riserList[lastIndex].coord,color )
    pathVector.append(tempIndex + 1)
    totalDistance += tempDistance
    lastIndex = tempIndex
    riserList[tempIndex].stacked = True
    
    tempIndex, tempDistance = nearestZone(riserList[lastIndex].coord, color )
    pathVector.append(tempIndex + 1)
    totalDistance += tempDistance
    
    print()
    print(f'The best {color} path is {pathVector} with a distance of {totalDistance}')
    
    return path(pathVector, totalDistance, color)

def bestColor(startCoord):
    bestPath = pathThree(startCoord, "Orange")
    color = "Orange"
    print()
    currPath = pathThree(startCoord, "Purple")
    if(bestPath.distance > currPath.distance):
        unStackPath(bestPath)
        bestPath = currPath
        color = "Purple"
    else:
        unStackPath(currPath)
    print()
    currPath = pathThree(startCoord, "Blue")
    if(bestPath.distance > currPath.distance):
        unStackPath(bestPath)
        bestPath = currPath
        color = "Blue"
    else:
        unStackPath(currPath)
        
    zoneList[bestPath.vector[3]-1].stacked = True
    zoneList[bestPath.vector[3]-1].row.color = color
    print()
    print(f'The best path is {color} {bestPath.vector} with a distance of {bestPath.distance}')   
    return bestPath

def fullPath(startCoord):
    pathList = list()
    print()
    print("Evaluating Path 1")
    print("--------------------------")
    tempPath = bestColor(startCoord)
    lastIndex = tempPath.vector[3];
    pathList.append(tempPath)
    totalDistance = 0;

    for i in range(0,8):
        print()
        print(f'Evaluating Path {i+2}')
        print("--------------------------")
        pathList.append(bestColor(zoneList[lastIndex].coord))
    print()
    print("Final Path")
    print("--------------------------")
    for path in pathList:
        print(f'{path.vector}, {path.color}')
        totalDistance += path.distance
    print(f'Total Distance: {totalDistance}')
    return pathList
#driver code
print("Zone Coordinates")
for zone in zoneList:
    print(f'{zone.coord.x},\t{zone.coord.y}')

print()
print("Riser Coordinates")
for riser in riserList:
    print(f'{riser.coord.x},\t{riser.coord.y},\t{riser.color}')

print("")
print("begining pathing")

fullPath(coordinate(36,66))
# print(f'risers stacked: {countStacked()}')

