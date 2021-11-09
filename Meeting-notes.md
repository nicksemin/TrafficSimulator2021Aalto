# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting dd.mm.2021 HH::MM

**Participants**: 
1. Member 1
2. Member 2
3. Member 3
4. Member 4 

## Summary of works
1. Member 1 
   
   Implementing the class XX. Tested the class XX. 
   Results are in `tests/<class-xx-tests>`. Resolved the identified problems.

2. Member 2

   Same as above

3. ...

## Challenges

1. The integration of UI with the monsters requires an abstract interface.
2. ...

## Actions
1. Member 1 is going to look into defining an abstract interface for monsters 
   to enable easy UI integration.
2. Member 2 is going to work with Member 1 to use abstract interface in derived 
   monster classes.
3. Member 2 is going to test the interface.
4. Member 3 is going to use ...

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
Short summary of current project status. 

### TODOs
1. Member 1: Write an action.
2. ...


***

# Meeting 09.11.2021 18::10

**Participants**: 
1. Alexey
2. Nikolai
3. Nikita
4. Emma

## Summary of works
1. Alexey 
   
   Planning and developing the Road/Intersection/CityObject-classes 

2. Nikolai

   Planning the Road-class, working with git-policies, looking into pathfinding algorithms
   
3. Nikita

   Setting up Cmake, initializing Vehicle-class

4. Emma

   Mainly setting up git, starting with Building-class

## Challenges

The meeting started with discussion about the policies regarding the use of git, mainly branching practices. It was agreed that simple "standalone" features can be committed straight to master, but wider spread functionalities should be developed inside their own branches. The overall aim is to keep the working tee as simple as possible.

Next, Nikolai presented his idea of how the Road-class should be structured. 
This was followed by Alexey's presentation of the same matter. The principal details were agreed upon and Alexey went on describing and demonstrating the features the features he had readily implemented.

Afterwards, several central concepts regarding the simulation were discussed:
   
**The functionality of the Intersection-class**

Intersections are to act as moderators pushing vehicles from roads to other roads or buildings, possibly following traffic lights. Alexey will take over this class as well, since the functionality is closely related to that of his Road-class.

**Vehicle speeds, lanes, possibility of vehicles overtaking, traffic lights**

The necessity for having specific speed for different vehicles was discussed. The common agreement was to go with road-wise speed limits for now. The possibility of vehicles overtaking each other is left for further consideration. Alexey has already started to implement traffic lights.

**Overall city structure - graph vs. coordinates**

The path finding is most likely implemented considering the city as a graph with with roads as edges and intersections as nodes. However, the way building locations are represented is yet to be determined.

**Representing building locations**

An approach of placing buildings on alongside "road slots" was proposed. This was not yet agreed upon.

**Handling time**

Time will probably be handled though a separate Simulation class, that will use a while loop and call the moveCars()-function of RoadLineClass at each tick. Alexey has already implemented the basic functionality.

**Additionally**

Alexey proposed the use of unsigned ints in whenever whenever there's a need strictly nonnegative (indexing) values.

## Actions

As this weeks meeting was mostly about clarifying definitions set in the project plan last week, no new specific actions were assigned. Everyone will keep oon developing base classes of their responsibility. We hope to have a working baseline implementation of vehicles moving on a simple road structure from building to building by next week.
Changes in project plan: CrossRoadClass now to be handled by Alexey due to a close connection with RoadLineClass

## Project status 

The overall structure starts to take shape. The development of Road-class functionalities is well under way and it will define the features required from other classes. Pathfinding will probably be the next major issue to be tackled.

### TODOs

As mentioned above, everyone will continue working on their respective classes.

Milestone next meeting, Alexey to be done: to have a hardcoded sample of several roads connected by intersections
and moving random cars for a couple of minutes.