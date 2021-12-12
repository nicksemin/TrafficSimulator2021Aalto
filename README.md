# Traffic simulator - Group 1

TThe aim of this software project was to build a system that can simulate city traffic throughout a day. The software has a modular structure where each and every class is supposed to be able to function separately and their interaction is what produces the simulation output.
The software is structured so that it is possible for the end user to provide various infrastructural input and then simulate city traffic with varying population sizes and timescales. By default, the initial parameters are set so that it best serves simulations of one day (24 h), and the default starttime is set to 00:00 at midnight.
The output of the software is a csv file containing the average hourly traffic details of all input roads. In addition, the user can specify a specific road to analyze. For this road the hourly averages are outputted as a relative histogram and possible traffic jams are detected separately.


# Group
- Member 1 Nikita Tarutin
- Member 2 Emma Rauhala
- Member 3 Nikolai Semin
- Member 4 Alexey Serous

# Repository organization
Your project implementation should follow the skelaton organization in this repository.
See readme.md files in each folder.


#How to run the project
Prerequisites:
Installed Cmake tool: https://cmake.org/install/
Installed g++ compiler

The simplest way to access the functionalities of the software is the basic command line interface. The software can be built with cmake simply by running the following commands in the project folder (traffic-simulator-1).
1) mkdir build
2) cd build
3) cmake ../
4) cmake –build ./


Then running .\simulation will start the program and make it ask for user input. The recommended way is to straightforwardly type i.e.

./simulation input_file/samplecity.txt 8000 25 output_file/output.csv 58

which will run a 24 h simulation with 8000 residents on the sample city, with a more specific analysis on a heavily trafficked road number 58.

./tests.sh will lauch tests.

#Working with git and the codebase
1) Create new branch for the feature you are working it 
2) Pull from master before committing
3) Commit often 
4) Review code of your counterparts and give comments
5) Before merging system-critical features create pull requests

# Project Implementation 
You must use git repository for the work on the project, making frequent enough commits so 
that the project group (and course staff) can follow the progress.

The completed project work will be demonstrated to the group's advisor at a demo session. 
The final demonstrations are arranged on week 50. After the final demonstrations project group 
evaluates another project, and self-evaluates own project. In addition, project members will 
give a confidential individual assessment of each group member

The course staff should be able to easily compile the project work using makefile and related 
instructions provided in the git repository. The final output should be in the **master branch** of the git repository.

# Working practices
Each project group is assigned an advisor from the project teaching personnel. 
There will be a dedicated Teams channel for each project topic to facilitate discussion between 
the groups in the same topic and the advisor. 

**The group should meet weekly.** The weekly meeting does not need to be long if there are no special issues 
to discuss, and can be taken remotely as voice/video chat on the group Teams channel (or Zoom or other similar tool), 
preferably at a regular weekly time. In the meeting the group updates:

- What each member has done during the week
- Are there challenges or problems? Discuss the possible solutions
- Plan for the next week for everyone
- Deviations and changes to the project plan, if any
- After the meetings, the meeting notes will be committed to the project repository in the `Meeting-notes.md` file. 
    * The commits within the week should have some commit messages referring to the meeting notes so 
      that the project advisor can follow the progress.  
    * **The meeting notes should be in English.**

> Everyone may not be able to participate to all meetings, but at least a couple of members should be present in each meeting. 
> Regular absence from meetings will affect in individual evaluation.

# Source code documentation
It is strongly recommended to use Doxygen to document your source code.
Please go over the *Project Guidelines* for details.

# TODOs
The team is planning to use Gitlab jira-like tools to select and close tickets
