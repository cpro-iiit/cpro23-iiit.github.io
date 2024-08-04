---
title: "Lab 0"
bookHidden: false
marp: true
header: 'CS0.101 Computer Programming (Monsoon 24)'
footer: '![width:100px](IIIT_Hyderabad_Logo.jpg)'
---

# Welcome to CS0.101 Lab 0

https://cpro-iiit.github.io/docs/course_material/labs/0/lab0.pdf

---
## Introduction
Coding can be learnt only by solving programming problems!

80% of wieghtage of evaluations is on programming problems.

> __Goal__: Solve 8-9 programming problems every week. 
> (3 in lab, 2 in tutorial, 1-2 in assignment, 2 in practice)
> Solve 100 over the entire course.   

Lab sessions are evaluated (2% marks per lab, 20% for 10 labs).

---
## Whats the plan for Lab 0?

1. Help you setup the coding environment.
2. Downloading problems and learn basic tools required for coding.
3. Submiting solutions and seeing the score.
4. Solve a hello world problem.
---
## Some Buzz Words!
__AutoLab__: where all labs/assignments problems are set. You can download handouts, and upload solutions (or handins). Autolab will automatically grade your solutions and give you a score. You will also get feedback on code from TAs here. You can access autolab in 2 ways.
1. Through the website https://pingala.iiit.ac.in
2. Through autolab commands in the _pingala shell_.

__Pingala Shell__: where you will do all the coding. The _pingala shell_ a standard ubuntu linux shell which has all the programs required for this course. This also ensures that the outputs/error that you encounter is similar for the entire batch.


---


## 1. Basic Setup


---


### 1.1 Reseting Password for AutoLab: 
1. Open a browser and go to https://pingala.iiit.ac.in (which is the web interface for autolab). 
2. Reset your password using forgot password. Username is IIIT email id. 
3. Goto Outlook Mailbox for instructions for reset.
4. After reseting, login to the site and keep this browser window open as it is also needed for step 1.3.

>Remember this password!. It will be used for all labs, assignmnets and exams.


---
### 1.2 Open  pingala shell: 

1. Open Terminal in lab machines and run the command
```bash
ssh <your_iiit_username>@pingala.iiit.ac.in
```
2. Enter your IIIT CAS password to open the _pingala shell_.

_pingala shell_ a standard ubuntu linux shell which has all the programs required for this course.

---
### 1.3 Setup AutoLab in shell: 
1. Run the following command for setting up autolab in _pingala shell_
```bash
autolab setup
```

2. Copy the 6 character access code and paste it at https://pingala.iiit.ac.in/activate in the same browser window where you logged in.

---
## 2. Download Problems/Basic Tools for Coding

---
### 2.1 Download Problems
1. Run the  command `autolab courses` to list the courses

2. Run the command `autolab asmt <course_id>` to list the assesments under the courses. <course_id> is "cs0-101-m24" for this course (as shown by previous command).

3. Run the command `autolab download <course_id>:<asmt_id>` to download the handout for Lab 0. <asmt_id> is "lab0" for Lab 0 (as shown by previous command).

More Info: https://docs.autolabproject.com/command-line-interface/

---
### 2.2 Navigate folders, edit code, extract/create tar archive in pingala shell

- use `ls` command to list folders and files in current directory.
- use `cd` to change the directory.
- use `tar xvf <file_name>` to unzip tar archives.
- use `nano <file_name>` to edit `<file_name>` as a text file.
- use `tar cvf <tar_file_name> <folder_name>` to create tar archive (similar to zip file) for the folder <folder_name>.

More Info: https://missing.csail.mit.edu/2020/course-shell/ 

---
### 2.3 Test your solutions locally
- run `make all` to compile both your problem solutions. If its run inside problem diretory only that problem is compiled.
- run `./main` in each of the problem directory to see your program running.
- run `sh driver.sh` to see your program running on test cases. 


---
## 3. Submitting Solutions/Seeing Score 

---
### 3.1 Submit solutions
1. go 1 directory above using `cd ..` (now `ls` should show `l0-handout` directory) and create a tar archive of the entire assesment by running
```tar cvf l0-handin.tar l0-handout```
2. submit `l0-handin.tar` using the command
```autolab submit lo-handin.tar```

---
### 3.2 See your score

see your score by running
```autolab scores```

---
## 4. Solve Lab 0

---
### 4.1 Tresure Hunt!

Use above clues to solve lab 0 with full marks.

1. Make guesses, try it out.

2. Only when you are completely stuck, ask others.

3. Understand why a guess didn't work out.
---
### Honor Code

> When you copy, you are only damaging yourself!




---
## Questions
---
### Can I use my computer/editor for coding?
Yes. You can access Autolab through the website (https://pingala.iiit.ac.in) as long as you are connected to IIIT network directly or indirectly through VPN.

Autolab command line could also be installed in linux systems using directions provided at the links bellow:  
https://github.com/autolab/autolab-cli   
https://docs.autolabproject.com/command-line-interface/  

However its reccomended to use the __pingala shell__ where everything is already installed. This ensures that you can get help from your colleages and TAs easily. This is also the same setup used for all exams.

---
## Thanks