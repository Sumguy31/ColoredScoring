import numpy as np
import matplotlib.pyplot as plt
import csv

zoneList = list()
riserList = list()
zoneX = list()
zoneY = list()
orangeX = list()
orangeY = list()
purpleX = list()
purpleY = list()
blueX = list()
blueY = list()
coordList = list()


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
        zoneX.append(int(row[0])*6)
        zoneY.append(int(row[1])*6)

with open('riserCoordinate.csv', newline='') as csvfile:
    riserCoordReader = csv.reader(csvfile, delimiter= ',')
    for row in riserCoordReader:
        if(int(row[2]) == 0):
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Orange"))
            orangeX.append(int(row[0])*6)
            orangeY.append(int(row[1])*6)
        elif(int(row[2]) == 1):
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Purple"))
            purpleX.append(int(row[0])*6)
            purpleY.append(int(row[1])*6)
        else:
            riserList.append(riser(coordinate(int(row[0])*6, int(row[1])*6), "Blue"))
            blueX.append(int(row[0])*6)
            blueY.append(int(row[1])*6)
            
coordList.append(coordinate(36,66))
with open('path.csv', newline='') as csvfile:
    pathReader = csv.reader(csvfile, delimiter= ',')
    for row in pathReader:
        coordList.append(coordinate(riserList[int(row[0])-1].coord.x,riserList[int(row[0])-1].coord.y))
        coordList.append(coordinate(riserList[int(row[1])-1].coord.x,riserList[int(row[1])-1].coord.y))
        coordList.append(coordinate(riserList[int(row[2])-1].coord.x,riserList[int(row[2])-1].coord.y))
        coordList.append(coordinate(zoneList[int(row[3])-1].coord.x,zoneList[int(row[3])-1].coord.y))


def getArrowData(startCoord,endCoord):
    xdiff = endCoord.x - startCoord.x
    ydiff = endCoord.y - startCoord.y
    return startCoord.x,startCoord.y, xdiff, ydiff

def plotPath():
    for i in range(32,36):
        x,y,dx,dy = getArrowData(coordList[i], coordList[i+1])
        plt.arrow(x,y,dx,dy,head_width = 1.5, head_length = 1.5)

fig=plt.figure()

ax=fig.add_axes([0,0,1,1])
ax.set_title('Step 9')
ax.scatter(zoneX,zoneY, color = 'black')
ax.scatter(orangeX,orangeY, color = 'orange')
ax.scatter(purpleX,purpleY, color = 'purple')
ax.scatter(blueX,blueY, color = 'blue')
plotPath()

plt.show()
