# ColoredScoring
To the VEXIQ students, I realize this may go over many of your heads, possibly due to my poor explanations, but I encourage you to stick through it. You’ll likely find it very interesting.

To the VEXIQ coaches, I, unlike many of you, am not a professional teacher. But this game presents a great opportunity to introduce to students some of the higher level topics in robotics: navigation, machine learning, and the famous Traveling Salesman Problem. This is a great time to expose students to new topics, and I hope you will do a better job than me to teach this.
## Introduction
Entertain for a moment a bored high school senior. Upon hearing the prompt of this year’s game, my first question was “What color configuration scores the most points while traveling the least distances?” This might seem trivial at first (I certainly thought it was), but is actually a pretty interesting problem.

I tried to create an algorithm to solve this problem, and so far I’ve come up with two solutions which I’ve shared below. All of the code, pathing, data, and visualization can be viewed through this github repository. I apologize in advance for the messy code.

Refer to the field diagram in visualization for my naming scheme. For titling purpose, row one refers to the bottom row, row two the middle, and row three the top.

## Solution 1 - Closest Zone: Orange, Purple, Blue

see: ColorScoring\Project1\Source.cpp
My first approach was to find the distance between each riser and each zone (*see: ColorScoring\Project1\dist_annotated.csv) and calculate the minimum distance needed to travel to a zone while still preserving the given color combination.
For this solution I did all my calculations in arbitrary units where 1 unit = 6 inches
An evaluation of all 6 row color combinations spit out this:

>OrangePurpleBlue
>total distance: 118.678

>OrangeBluePurple
>total distance: 121.939

>PurpleOrangeBlue
>total distance: 126.777

>PurpleBlueOrange
>total distance: 128.489

>BlueOrangePurple
>total distance: 123.09  

>BluePurpleOrange
>total distance: 121.541

for riser-zone assigments see : ColorScoring\Project1\rowZone.csv
It can be read as such: for the OPB solution, riser 1 goes to zone 2, riser 2 goes to zone 2. riser 3 goes to zone 8 and so on

note: this is not documented on my github, because I didn’t store the debug file, but the column arrangements were vastly inferior to the row configuration. From memory, the shortest distance as approximately ~185 units

It at this point that I was about 8 hours into the project when I realized that this is just a heavily modified version of the Traveling Salesman Problem, a very famous and well studied np-hard problem.

However this solution might be considered “good enough” assuming:
a) you are able to score ALL risers with the time limit
b) you only have to move the risers to the zone, and do not have to travel to the riser

It is assumption b that is the real killer to this solution, once you start considering distance to get to an object you enter a point where the computation of the shortest path takes many more computations to find. This is what is meant by np-hard, as more points are added it becomes increasingly unrealistic to test every possible path. Which brings us to our next solution:

## Solution 2 - Nearest Neighbor: Blue, Orange, Purple

At this point I did two things:
a) I switched to Python
b) I converted from arbitrary units to actual inches

I also made a couple of assumptions:
a) There is only one robot on the field
b) Robot turns take a negligible amount of time
c) That robot has the capacity to carry 3 risers
d) It is always more optimal to pick up 3 risers rather than say pick up 2 and then come back and score a third (which isn’t guaranteed to be true).

For this solution, I implement what some call a greedy search. From the starting coordinate (36,66), the program looked for the shortest path to score using the following algorithm:

Find the closest riser of a given color from the robot’s current location
Find the closest riser of a given color from the first riser
Find the closest riser of a given color from the second riser
Find the closest zone which is either a) in a row with a stack of the same color or b) in a row without any stacks
Record the distance needed to travel that path.
The program would then run through those steps for each riser color. Then chose the shortest path. Running the algorithm for each zone returns the following path (which is visualized nicely thanks to mathplotlib for python): which can be seen in visualization

This path has a total distance of 1303 inches( see: ColoredScoring\Pathing\Output.txt).
note there are some choices the algorithm makes which I can’t explain. For example, step 3 is suggested as R21>R24>R11>Zone6, but I’m fairly certain the optimal path would be R11>R21>R24>Zone6.

You’ll notice that the greedy approach ends up hurting us in the end because as we take more and more steps the robot has to choose longer and longer paths to get to its destination.
This is not necessarily a bad thing, especially at the beginning of the season where most teams will not clear the field anyways. In fact steps 1-4 are actually quite reasonable, so running steps 1,2,3,5, might be a good way to get a fairly high score when you inevitably get the “bad team” which scores poorly.

Please note THIS IS NOT THE OPTIMAL PATH TO SCORE ALL RISERS, in fact, I’d estimate this path is 30-45% longer than the optimal path due to heavy cross-field travel done in steps 7-9.

A better path could be attained by evaluating more paths before making a decision, or perhaps our next solution…

## Solution 3 - Machine Learning: ???

The best way to find the optimal path would be through a technique called Machine Learning or Evolutionary Computing, a technique I have never used nor really deeply looked into. For worse or for better, Python and R (the choice programming language of many data scientist and machine learning enthusiast) are two of my weakest languages.

For more information on Machine Learning as it relates to the Traveling Salesman Problem, I’d refer you to the TSP wikipedia page. Look for the section on Ant Colony Simulation. Marco Dorigo’s work is actually quite fascinating.

This solution is still being developed, for my knowledge in ML at this point is very little, but if you have any questions feel free to reach out to me and I will do my best to answer.
