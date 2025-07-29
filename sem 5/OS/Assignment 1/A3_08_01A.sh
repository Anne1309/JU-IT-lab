#!/bin/bash
#
#Team: 08 , Date:22/7/25
#Name: Debodit Ray, Roll: 13
#Name: Kaustav Mondal, Roll: 17
#Name: Anuska Nath, Roll: 3

#Assignment 1A


#Assigment Description: Run the commands and validate the output



# Q1. who:-It displays the information about all the users who have logged into the system currently 

#who

#(unknown) :0       	2024-10-21 11:46 (:0)
#root 	pts/0    	2025-07-22 11:15 (172.16.5.159)
#be2304   pts/1    	2025-07-22 15:47 (172.16.4.230)
#be2311   pts/3    	2025-07-22 15:49 (172.16.4.231)
#be2314   pts/4    	2025-07-22 16:06 (172.16.4.205)
#be2349   pts/6    	2025-07-22 16:06 (172.16.4.218)
#be2382   pts/7    	2025-07-22 16:06 (172.16.4.207)
#be2339   pts/8    	2025-07-22 16:07 (172.16.4.216)
#be2337   pts/9    	2025-07-22 16:07 (172.16.4.210)
#be2330   pts/10   	2025-07-22 16:07 (172.16.4.203)
#be2392   pts/12   	2025-07-22 16:08 (172.16.4.201)
#be2390   pts/13   	2025-07-22 16:11 (172.16.4.212)
#be2350   pts/14   	2025-07-22 16:12 (172.16.4.209)
#be2303   pts/15   	2025-07-22 16:14 (172.16.4.227)
#be2342   pts/16   	2025-07-22 16:19 (172.16.4.215)
#be2313   pts/18   	2025-07-22 16:22 (172.16.4.228)



# Q2. whoami:- It displays Current username, Terminal number, date and time at which user logged into the system

#whoami

#be2313



# Q3. pwd:- It displays current working directory

#pwd

#/home/usr/student/ug/yr23/be2313



# Q4. date:- It displays system date and time

#date

#Tue Jul 22 16:25:27 IST 2025



# Q5. ls - It lists the files and directories stored in the current directory. To list the files in a directory use the following syntax: $ls dirname

#ls

#A1  A2  A3  A3_08_01A.sh  A4  A5  A6  A7  A8  a.out  assign1  CN  destinationfile.c  diamond.exe  DSA  OOP  OOP_VIVA  OOS  SE  test.c  text.c



# Q6. mkdir – It is used to create directories by using the command: $mkdir dirname

#mkdir Demo;ls

#A1  A3            A4  A6  A8     assign1  Demo               diamond.exe  OOP       OOS  test.c
#A2  A3_08_01A.sh  A5  A7  a.out  CN       destinationfile.c  DSA          OOP_VIVA  SE   text.c



# Q7. clear - It clears the screen

#clear;echo "The screen is cleared"

#The screen is cleared



# Q8. cd - It is used to change the current working directory to any other directory specified

#ls;cd A1;ls

#A1  A3            A4  A6  A8     assign1  Demo               diamond.exe  OOP       OOS  test.c
#A2  A3_08_01A.sh  A5  A7  a.out  CN       destinationfile.c  DSA          OOP_VIVA  SE   text.c
#A1Q2.c  A1Q3.c  A1Q4.c  A1Q5.c  A1Q6.c  a.out  calculator.c  fibonacci.c



# Q9. df - It displays currently mounted file systems.

#df

# Filesystem               	1K-blocks  	Used  Available Use% Mounted on
#/dev/mapper/scientific-root   52399104  27794216   24604888  54% /
#devtmpfs                  	32758584     	0   32758584   0% /dev
#tmpfs                     	32774652 	10340   32764312   1% /dev/shm
#tmpfs                     	32774652	789148   31985504   3% /run
#tmpfs                     	32774652     	0   32774652   0% /sys/fs/cgroup
#/dev/sda2                  	1039616	238088 	801528  23% /boot
#/dev/mapper/scientific-home 2256669952 136362376 2120307576   7% /home
#tmpfs                      	6554932    	16	6554916   1% /run/user/42
#tmpfs                      	6554932     	0	6554932   0% /run/user/3067
#tmpfs                      	6554932     	0	6554932   0% /run/user/3097
#tmpfs                      	6554932     	0	6554932   0% /run/user/3014
#tmpfs                      	6554932     	0	6554932   0% /run/user/3107
#tmpfs                      	6554932     	0	6554932   0% /run/user/3218
#tmpfs                      	6554932     	0	6554932   0% /run/user/3213
#tmpfs                      	6554932     	0	6554932   0% /run/user/3271
#tmpfs                      	6554932     	0	6554932   0% /run/user/3292
#tmpfs                      	6554932     	0	6554932   0% /run/user/3211
#tmpfs                      	6554932     	0	6554932   0% /run/user/3209
#tmpfs                      	6554932     	0	6554932   0% /run/user/3223
#tmpfs                      	6554932     	0	6554932   0% /run/user/3275
#tmpfs                      	6554932     	0	6554932   0% /run/user/0
#tmpfs                      	6554932     	0	6554932   0% /run/user/3207
#tmpfs                      	6554932     	0	6554932   0% /run/user/3214
#tmpfs                      	6554932     	0	6554932   0% /run/user/3217
#tmpfs                      	6554932     	0	6554932   0% /run/user/3252
#tmpfs                      	6554932     	0	6554932   0% /run/user/3285
#tmpfs                      	6554932     	0	6554932   0% /run/user/3242
#tmpfs                      	6554932     	0	6554932   0% /run/user/3240
#tmpfs                      	6554932     	0	6554932   0% /run/user/3233
#tmpfs                      	6554932     	0	6554932   0% /run/user/3295
#tmpfs                      	6554932     	0	6554932   0% /run/user/3293
#tmpfs                      	6554932     	0	6554932   0% /run/user/3253
#tmpfs                      	6554932     	0	6554932   0% /run/user/3206
#tmpfs                      	6554932     	0	6554932   0% /run/user/3245
#tmpfs                      	6554932     	0	6554932   0% /run/user/3216
#tmpfs                      	6554932     	0	6554932   0% /run/user/3220
#tmpfs                      	6554932     	0	6554932   0% /run/user/3210




# Q10. rmdir - Directories can be deleted using the rmdir command - $rmdir dirname

#ls;rmdir Demo;ls

#A1            A4  A8       Demo               OOP       test.c
#A2            A5  a.out    destinationfile.c  OOP_VIVA  text.c
#A3            A6  assign1  diamond.exe        OOS
#A3_08_01A.sh  A7  CN       DSA                SE

#A1  A3_08_01A.sh  A6  a.out    destinationfile.c  OOP       SE
#A2  A4            A7  assign1  diamond.exe        OOP_VIVA  test.c
#A3  A5            A8  CN       DSA                OOS      



# Q11. cat – It displays the contents of a file - $cat filename

#cat destinationfile.c 

#include<stdio.h>
#int main(){
#
#int m1,n1,m2,n2,i,j,k;
#printf("Enter the row and column number of first matrix:\n");
#scanf("%d",&m1);
#scanf("%d",&n1);
#printf("Enter the rows and columns of second matrix:\n");
#scanf("%d",&m2);
#scanf("%d",&n2);
#int a[m1][n1];
#int b[m2][n2];
#if(n1==m2){
#printf("Enter the elements of first matrix:\n");
#for(i=0;i<m1;i++){
#for(j=0;j<n1;j++){
#scanf("%d",&a[i][j]);}}
#printf("Enter the elements of second matrix:\n");
#for(i=0;i<m2;i++){
#for(i=0;i<n2;i++){
#scanf("%d",&b[i][j]);
#}}
#int c[m1][n2];
#int sum=0;
#for(i=0;i<m1;i++){
#for(j=0;j<n2;j++){
#for(k=0;k<n1;k++){
#c[i][j]=sum;}
#sum=0;}}
#printf("The multiplication matrix is:\n");
#for(i=0;i<m1;i++){
#for(j=0;j<n2;j++){
#printf("%d",c[i][j]);}
#printf("\n");}}
#else{
#printf("Wrong input");}
#return 0;}



#12> cp - It is used to copy a file - $ cp source_file destination_file

#cp destinationfile.c test.c; echo "File copied"

#File copied



#13> mv- It is used to change the name of a file - $ mv old_file new_file

#mv destinationfile.c newdestfile.c; echo "File moved"

#File moved



#14> rm – It is used to delete an existing file - $ rm filename

#rm test.c; echo "file removed"

#file removed



#15> stat- It is used to display file or file system status - $ stat filename

#stat newdestfile.c 

#  File: âwdestfile.câ Size: 776             Blocks: 8          IO Block: 4096   regular file
#Device: fd02h/64770d    Inode: 537426961   Links: 1
#Access: (0644/-rw-r--r--)  Uid: ( 3216/  be2313)   Gid: ( 2926/  ugyr23)
#Context: unconfined_u:object_r:user_home_t:s0
#Access: 2025-07-22 17:48:29.738902854 +0530
#Modify: 2025-07-22 16:58:25.606833623 +0530
#Change: 2025-07-22 17:51:55.932907606 +0530
# Birth: -



#16> ln - It is used to create links between files and directories.

#ln newdestfile.c newdestlink1.c;echo "link created"

#link created



#17> tty – It prints the filename of the terminal connected to standard input.

#tty

#/dev/pts/0



#18> uname –It prints system information
#uname

#Linux



#19> umask – It specifies user file creation mask, implying which of the 3 permissions are to be denied to the owner,group and others.

#umask

#0022



#20> find – It searches for files in a directory hierarchy

#find diamond.exe; echo "file found"

#diamond.exe
#file found



#21) sort – It sorts the lines of text files

#echo "banana" >fruits.txt; echo "apple" >>fruits.txt; echo "cherry" >> fruits.txt; echo "date" >> fruits.txt; sort fruits.txt

#apple
#banana
#cherry
#date



#22) ps - It displays information about the current processes.

#ps

#  PID TTY          TIME CMD
#28991 pts/4    00:00:00 bash
#29290 pts/4    00:00:00 ps



#23) chmod 777 file1 - gives full permission to owner, group and others

#touch file1.txt; ls -l file1.txt; chmod 777 file1.txt; ls -l file1.txt

#-rw-r--r--. 1 be2303 ugyr23 0 Jul 22 17:40 file1.txt
#-rwxrwxrwx. 1 be2303 ugyr23 0 Jul 22 17:40 file1.txt



#24) grep - It finds specific patterns in files.

#echo "apple is red" > colors.txt; echo "banana is yellow" >> colors.txt; echo "cherry is red" >> colors.txt; echo "grape is green" >> colors.txt; grep 'red' colors.txt

#apple is red
#cherry is red



#25) touch - It creates an empty file or updates the timestamp of an existing file.

#touch new_empty_file.txt; ls -l new_empty_file.txt; ls -l fruits.txt;

#-rw-r--r--. 1 be2303 ugyr23 0 Jul 22 17:43 new_empty_file.txt
#-rw-r--r--. 1 be2303 ugyr23 25 Jul 22 17:38 fruits.txt

#sleep 5; touch fruits.txt; ls -l fruits.txt

#-rw-r--r--. 1 be2303 ugyr23 25 Jul 22 17:44 fruits.txt



#26) more/less - It displays file content one screen at a time, allowing you to scroll.

#seq 1 5 > numbers.txt; less numbers.txt

#1
#2
#3
#4
#5
#numbers.txt (END)



#27) head/tail - It displays First/Last 10 lines of a File.

#head numbers.txt

#1
#2
#3
#4
#5

#head -n 3 numbers.txt

#1
#2
#3

#tail -n 3 numbers.txt

#3
#4
#5



#28) top - It dynamically displays real-time information about system statistics.

#top

#top - 17:49:09 up 274 days,  6:02,  6 users,  load average: 0.00, 0.01, 0.05
#Tasks: 330 total,   1 running, 326 sleeping,   0 stopped,   0 zombie
#%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni, 99.9 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
#KiB Mem : 65549308 total, 53935244 free,  2282840 used,  9331224 buff/cache
#KiB Swap: 32899068 total, 32899068 free,        0 used. 61724352 avail Mem
#
#  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
#24782 be2313    20   0  147988   2452   1120 S   0.3  0.0   0:00.51 sshd
#    1 root      20   0  194444   7592   3988 S   0.0  0.0  29:17.01 systemd
#    2 root      20   0       0      0      0 S   0.0  0.0   0:25.56 kthreadd
#    3 root      20   0       0      0      0 S   0.0  0.0 360:10.19 ksoftirqd/0
#    8 root      rt   0       0      0      0 S   0.0  0.0   0:04.44 migration/0
#    9 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcu_bh
#   10 root      20   0       0      0      0 S   0.0  0.0 327:30.27 rcu_sched
#   11 root      rt   0       0      0      0 S   0.0  0.0   1:06.82 watchdog/0
#   12 root      rt   0       0      0      0 S   0.0  0.0   1:05.75 watchdog/1
#   13 root      rt   0       0      0      0 S   0.0  0.0   0:13.30 migration/1
#   14 root      20   0       0      0      0 S   0.0  0.0 260:50.16 ksoftirqd/1
#   16 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/1:0H
#   17 root      rt   0       0      0      0 S   0.0  0.0   1:00.07 watchdog/2
#   18 root      rt   0       0      0      0 S   0.0  0.0   0:08.14 migration/2
#   19 root      20   0       0      0      0 S   0.0  0.0 200:43.17 ksoftirqd/2
#   21 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/2:0H
#   22 root      rt   0       0      0      0 S   0.0  0.0   0:59.06 watchdog/3
#   23 root      rt   0       0      0      0 S   0.0  0.0   0:06.01 migration/3
#   24 root      20   0       0      0      0 S   0.0  0.0 167:21.15 ksoftirqd/3
#   26 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/3:0H
#   27 root      rt   0       0      0      0 S   0.0  0.0   1:01.78 watchdog/4
#   28 root      rt   0       0      0      0 S   0.0  0.0   0:02.03 migration/4
#   29 root      20   0       0      0      0 S   0.0  0.0 243:32.45 ksoftirqd/4
#   31 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/4:0H
#   33 root      rt   0       0      0      0 S   0.0  0.0   0:56.04 watchdog/5
#   34 root      rt   0       0      0      0 S   0.0  0.0   0:10.62 migration/5
#   35 root      20   0       0      0      0 S   0.0  0.0 213:41.60 ksoftirqd/5
#   37 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/5:0H
#   38 root      rt   0       0      0      0 S   0.0  0.0   0:56.91 watchdog/6
#   39 root      rt   0       0      0      0 S   0.0  0.0   0:03.37 migration/6
#   40 root      20   0       0      0      0 S   0.0  0.0 175:18.42 ksoftirqd/6
#   42 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/6:0H
#   43 root      rt   0       0      0      0 S   0.0  0.0   0:59.12 watchdog/7
#   44 root      rt   0       0      0      0 S   0.0  0.0   0:02.39 migration/7
#   45 root      20   0       0      0      0 S   0.0  0.0 154:17.47 ksoftirqd/7 



#29) kill - It terminates a Process.

#sleep 300 &

#[1] 29673

#jobs -l

#[1]+ 29673 Running                 sleep 300 &

#kill 29673



#30) history - It displays a list of previously executed commands.

#history

#   36  ./server 15000
#   37  gcc datagram_server.c
#   38  ./a.out 15000
#   39  ls
#   40  cd CN
#   41  ls
#   42  cd assign1
#   43  ls
#   44  gcc datagram_client.c -o client
#   45  ./client
#   46  gcc datagram_client.c -o client
#   47  ./client 15000
#   48  gcc datagram_client.c
#   49  ./a.out 15000
#   50  ls
#   51  cd CN
#   52  ls
#   53  cd assign1
#   54  ls
#   55  gcc datagram_client.c -o client
#   56  ./client 15000
#   57  ls
#   58  cd CN
#   59  ls
#   60  cd assign1
#   61  ls
#   62  gcc datagram_server.c -o server
#   63  ./server
#   64  ./server 15000
#   65  ls
#   66  cd CN
#   67  ls
#   68  cd assign2
#   69  ls
#   70  cd q1
#   71  ls
#   72  cd ..
#   73  ls
#   74  cd ..
#   75  ls
#   76  cd ..
#   77  ls
#   78  cd oos
#   79  ls
#   80  mkdir a5
#   81  ls
#   82  cd a5
#   83  ls
#   84  nano q1.java
#   85  javac q1.java
#   86  java FactoryPatternDemo
#   87  nano q1.java
#   88  javac q1.java
#   89  java FactoryPatternDemo
#   90  ls
#   91  nano q2.java
#   92  javac q2.java
#   93  java DecoratorPatternDemo
#   94  nano q3.java
#   95  javac q3.java
#   96  java MediatorPatternDemo
#   97  ls
#   98  nano q1.java
#   99  nano q2.java
#  100  rm q2.java
#  101  nano q2.java
#  102  rm q3.java
#  103  nano q3.java
#  104  ls
#  105  javac q3.java
#  106  java MediatorPatternDemo
#  107  javac q2.java
#  108  java DecoratorPatternDemo
#  109  ls
#  110  cd CN
#  111  ls
#  112  mkdir assign2
#  113  cd assign2
#  114  ls
#  115  mkdir q1
#  116  cd q1
#  117  ls
#  118  vi DLL_sender.cpp
#  119  rm DLL_sender.cpp
#  120  nano DLL_sender.cpp
#  121  nano DLL_reciever.cpp
#  122  cd ..
#  123  ls
#  124  mkdir q2
#  125  cd ..
#  126  ls
#  127  cd assign2
#  128  ls
#  129  rmdir q2
#  130  nano q2
#  131  ls
#  132  mv q2 q2.cpp
#  133  ls
#  134  cd q1
#  135  ls
#  136  cd ..
#  137  ls
#  138  nano q3.c
#  139  nano q4.c
#  140  ls
#  141  nano q5.c
#  142  ls
#  143  gcc q2.cpp
#  144  gcc q2.cpp -std=c99
#  145  gcc q3.c
#  146   ls
#  147  gcc q3.c
#  148  gcc -g q3.c test
#  149  nano q3.c
#  150  y
#  151  gcc q3.c
#  152  gcc q3.c -std=c99
#  153  ./a.out
#  154  nano q4.c
#  155  gcc q4.c -std=c99
#  156  ./a.out
#  157  nano q5.c
#  158  gcc q5.c -std=c99
#  159  ./a.out
#  160  ls
#  161  scp -r assign2/be2309@172.16.4.112
#  162  scp -r assign2/be2309@172.16.4.112:
#  163  scp -r assign2/ be2309@172.16.4.112:
#  164  cd ..
#  165  ls
#  166  scp -r assign2/ be2309@172.16.4.112:
#  167  ls
#  168  cd CN
#  169  ls
#  170  scp -r assign1,assign2 / be2317@172.16.4.112:
#  171  scp -r assign1 / be2317@172.16.4.112:
#  172  scp -r assign1/ be2317@172.16.4.112:
#  173  ls
#  174  cd CN
#  175  ls
#  176  cd assign2
#  177  ls
#  178  vi q2.c
#  179  rm q2.c
#  180  nano q2.c
#  181  ls
#  182  gcc q2.c -std=c99
#  183  ./a.out
#  184  rm q2.cpp
#  185  ls
#  186  cd q1
#  187  ls
#  188  nano DLL_sender.c
#  189  nano DLL_reciever.c
#  190  gcc DLL_sender.c -std=c99
#  191  ./a.out 8000
#  192  gcc DLL_sender.c -std=c99
#  193  ./a.out 15000
#  194  ls
#  195  rm DLL_sender.cpp
#  196  rm DLL_reciever.cpp
#  197  ls
#  198  cd ..
#  199  ls
#  200  scp -r q1/ be2309@172.16.4.112:
#  201  scp -r q2.c/ be2309@172.16.4.112:
#  202  ls
#  203  cd ..
#  204  ls
#  205  cd assign1
#  206  ls
#  207  nano dat_server.c
#  208  nano dat_client.c
#  209  ls
#  210  gcc -g dat_server.c server
#  211  gcc dat_server.c
#  212  ./a.out 15000
#  213  gcc dat_server.c
#  214  ./a.out 15000
#  215  ls
#  216  nano str_server.c
#  217  nano str_client.c
#  218  gcc str_server.c
#  219  ./a.out 15000
#  220  gcc str_server.c
#  221  ./a.out 17000
#  222  gcc str_server.c -o server
#  223  ./server
#  224  ls
#  225  rm str_server.c
#  226  rm str_client.c
#  227  nano str_server.c
#  228  nano str_client.c
#  229  ls
#  230  gcc str_server.c
#  231  ./a.out 1000
#  232  rm str_server.c
#  233  rm str_client.c
#  234  nano str_server.c
#  235  rm str_server.c
#  236  nano str_server.c
#  237  nano str_client.c
#  238  gcc str_server.c
#  239  ./a.out 1000
#  240  ls
#  241  rm str_server.c
#  242  rm str_client.c
#  243  gcc stream_server.c
#  244  ./a.out 1000
#  245  ./a.out 10000
#  246  ./a.out 9090
#  247  gcc stream_server.c
#  248  ./a.out 9090
#  249  gcc stream_server.c
#  250  ./a.out 9000
#  251  ./a.out 15000
#  252  ls
#  253  rm datagram_server.c
#  254  rm datagram_client.c
#  255  ls
#  256  mv dat_server.c datagram_server.c
#  257  mv dat_client.c datagram_client.c
#  258  ls
#  259  nano strser.c
#  260  nano strcli.c
#  261  gcc strser.c
#  262  ./a.out 9000
#  263  gcc strser.c
#  264  ./a.out 5000
#  265  gcc strser.c
#  266  ./a.out 5
#  267  gcc strser.c
#  268  ./a.out 8000
#  269  ls
#  270  gcc strser.c
#  271  ./a.out 8000
#  272  ls
#  273  rm stream_server.c
#  274  rm stream_client.c
#  275  ls
#  276  mv strcli.c stream_client.c
#  277  mv strser.c stram_server.c
#  278  ls
#  279  rm server
#  280  rm client
#  281  ls
#  282  cd ..
#  283  ls
#  284  cd assign2
#  285  ls
#  286  cd ..
#  287  ls
#  288  cd assign1
#  289  ls
#  290  nano strser.c
#  291  nano strcli.c
#  292  ls
#  293  gcc strser.c
#  294  ./a.out 8000
#  295  gcc strser.c
#  296  ./a.out 6000
#  297  gcc strser.c
#  298  ./a.out 6000
#  299  ./a.out 9000
#  300  ./a.out 8000
#  301  gcc strser.c
#  302  ./a.out 8000
#  303  ls
#  304  rm strser.c
#  305  rm strcli.c
#  306  rm stram_server.c stream_server.c
#  307  mv stram_server.c stream_server.c
#  308  ls
#  309  nano stream_server.c
#  310  gcc stream_server.c
#  311  ./a.out 8000
#  312  gcc stream_server.c
#  313  ./a.out 8000
#  314  ls
#  315  gcc str_ser.c
#  316  ./a.out 8000
#  317  gcc str_ser.c
#  318  ./a.out 3000
#  319  ls
#  320  rm stream_server.c
#  321  rm stream_client.c
#  322  mv str_ser.c stream_server.c
#  323  mv str_cli.c stream_client.c
#  324  ls
#  325  nano datagram_server.c
#  326  rm datagram_server.c
#  327  nano datagram_server.c
#  328  rm daragram_client.c
#  329  rm datagram_client.c
#  330  nano datagram_client.c
#  331  ls
#  332  gcc datagram_Server.c
#  333  gcc datagram_server.c
#  334  ./a.out 8000
#  335  gcc datagram_Server.c
#  336  gcc datagram_server.c
#  337  ./a.out 8000
#  338  rm datagram_server.c
#  339  nano datagram_server.c
#  340  rm datagram_client.c
#  341  nano datagram_client.c
#  342  gcc datagram_server.c
#  343  rm datagram_server.c
#  344  nano datagram_server.c
#  345  gcc datagram_server.c
#  346  ./a.out 6000
#  347  gcc datagram_server.c
#  348  ./a.out 6000
#  349  ls
#  350  cd ..
#  351  ls
#  352  scp -r assign2/ be2306@172.16.4.112:
#  353  ls
#  354  cd assign1
#  355  ls
#  356  nano raws.c
#  357  nano rawr.c
#  358  gcc raws.c
#  359  ./a.out 6000
#  360  rm raw_server.c
#  361  rm raw_client.c
#  362  mv raws raw_server.c
#  363  mv raws.c raw_server.c
#  364  mv rawr.c raw_client.c
#  365  ls
#  366  nano stream_server.c
#  367  ls
#  368  cd CN
#  369  ls
#  370  cd assign2
#  371  ls
#  372  cd q1
#  373  ls
#  374  gcc DLL_reciever.c -std=c99
#  375  ./a.out 8000
#  376  gcc DLL_reciever.c -std=c99
#  377  ./a.out 15000
#  378  ls
#  379  cd ..
#  380  ls
#  381  cd ..
#  382  ls
#  383  cd assign1
#  384  ls
#  385  gcc dat_client.c
#  386  ./a.out 15000
#  387  gcc dat_client.c
#  388  ./a.out 15000
#  389  ls
#  390  gcc str_client.c
#  391  ./a.out 15000
#  392  gcc str_client.c
#  393  ./a.out 17000
#  394  gcc str_client.c -o client
#  395  ./client
#  396  gcc str_client.c
#  397  ./a.out 1000
#  398  ls
#  399  gcc str_client.c
#  400  ./a.out 1000
#  401  gcc stream_client.c
#  402  ./a.out 1000
#  403  ./a.out 10000
#  404  ./a.out 9090
#  405  gcc stream_client.c
#  406  ./a.out 9090
#  407  gcc stream_client.c
#  408  ./a.out 9090
#  409  gcc stream_client.c
#  410  ./a.out 9000
#  411  ./a.out 15000
#  412  gcc strcli.c
#  413  ./a.out 9000
#  414  gcc strcli.c
#  415  ./a.out 9000
#  416  gcc strcli.c
#  417  ./a.out 5000
#  418  gcc strcli.c
#  419  ./a.out 5000
#  420  ./a.out 50000
#  421  gcc strcli.c
#  422  ./a.out 8000
#  423  gcc strcli.c
#  424  ./a.out 8000
#  425  ls
#  426  gcc strcli.c
#  427  ./a.out 8000
#  428  gcc strcli.c
#  429  ./a.out 6000
#  430  gcc strcli.c
#  431  ./a.out 6000
#  432  ./a.out 9000
#  433  gcc strcli.c
#  434  ./a.out 8000
#  435  ls
#  436  gcc stream_slient.c
#  437  gcc stream_0cient.c
#  438  gcc stream_client.c
#  439  ./a.out 8000
#  440  gcc stream_client.c
#  441  ./a.out 8000
#  442  ls
#  443  nano str_ser.c
#  444  nano str_cli.c
#  445  gcc str_cli.c
#  446  rm str_cli.c
#  447  nano str_cli.c
#  448  gcc str_cli.c
#  449  ./a.out 8000
#  450  gcc str_cli.c
#  451  ./a.out 8000
#  452  gcc str_cli.c
#  453  ./a.out 3000
#  454  ls
#  455  gcc datagram_client.c
#  456  ./a.out 8000
#  457  gcc datagram_client.c
#  458  ./a.out 8000
#  459  gcc server_client.c
#  460  gcc datagram_client.c
#  461  ./a.out 6000
#  462  gcc datagram_client.c
#  463  ./a.out 6000
#  464  ls
#  465  gcc rawr.c
#  466  cd ..
#  467  ls
#  468  cd ..
#  469  ls
#  470  cd oos
#  471  ls
#  472  mkdir eval
#  473  ls
#  474  cd eval
#  475  ls
#  476  vi q1
#  477  vi q2.java
#  478  vi q1.java
#  479  ls
#  480  rm q1
#  481  ls
#  482  cd oos
#  483  ls
#  484  cd oosLabEvaluation
#  485  ls
#  486  nano q1.java
#  487  javac ChangeCase.java
#  488  java ChangeCase
#  489  nano ChangeCase.java
#  490  java ChangeCase
#  491  javac ChangeCase.java
#  492  java ChnageCase
#  493  java ChangeCase
#  494  clear
#  495  ll
#  496  nano q1.java
#  497  nano q2.java
#  498  javac GCD.java
#  499  java GCD
#  500  nano q2.java
#  501  ls
#  502  nano q1.java
#  503  ls
#  504  cd ..
#  505  ls
#  506  cd a1
#  507  ls
#  508  cd ..
#  509  ls
#  510  cd ..
#  511  ls
#  512  logout
#  513  cd oos
#  514  ls
#  515  cd eval
#  516  ls
#  517  vi q1
#  518  ls
#  519  cd ..
#  520  ls
#  521  rmdir eval
#  522  cd eval
#  523  ls
#  524  rm q1
#  525  rm q1.java
#  526  rm q2.java
#  527  ls
#  528  cd ..ls
#  529  cd ..
#  530  ls
#  531  rmdir val
#  532  rmdir eval
#  533  ls
#  534  mkdir oosLabEvaluation
#  535  ls
#  536  cd oosLabEvaluation
#  537  vi q1.java
#  538  ls
#  539  vi q2.java
#  540  ls
#  541  nano q1.java
#  542  javac q1.java
#  543  nano q1.java
#  544  javac q1.java
#  545  nano q1.java
#  546  javac q1.java
#  547  nano q1.java
#  548  javac q1.java
#  549  nano q1.java
#  550  javac q1.java
#  551  nano q1.java
#  552  y
#  553  javac q1.java
#  554  nano q1.java
#  555  javac q1.java
#  556  nano q1.java
#  557  javac q1.java
#  558  nano q1.java
#  559  javac q1.java
#  560  nano q1.java
#  561  javac q1.java
#  562  ls
#  563  javac ChangeCase.java
#  564  java ChangeCase
#  565  vi ChangeCase.java
#  566  ls
#  567  javac GCD.class
#  568  javac GCD.java
#  569  java GCD
#  570  rm q1.java
#  571  rm q2.java
#  572  ls
#  573  nano ChangeCase.java
#  574  ls
#  575  javac ChangeCase.java
#  576  java ChangeCase
#  577  javac GCD.java
#  578  java GCD
#  579  ls
#  580  vi ChangeCase.java
#  581  ls
#  582  vi GCD.java
#  583  ls
#  584  vi ChangeCase.java
#  585  ls
#  586  cd CN
#  587  ls
#  588  cd assign1
#  589  ls
#  590  cd CN
#  591  s
#  592  ls
#  593  cd assignment1
#  594  ls
#  595  gcc udp_client.c
#  596  ./a.out 172.16.4.112 8000
#  597  gcc udp_client.c
#  598  ./a.out 172.16.4.112 8000
#  599  ls
#  600  gcc udp_client.c -o client
#  601  ./client 172.16.4.112 8000
#  602  gcc udp_client.c -o client
#  603  ./client 172.18.13.217 8000
#  604  gcc udp_client.c -o client
#  605  ./client 172.16.4.112 8000
#  606  ls
#  607  gcc tcp_client.c -o client
#  608  ./client 172.16.4.112 8000
#  609  ls
#  610  cd CN
#  611  ls
#  612  mkdir assignment1
#  613  mkdir assignment2
#  614  ls
#  615  cd assignment1
#  616  ls
#  617  gcc udp_server.c
#  618  ./a.out 8000
#  619  ./a.out 172.16.4.112 8000
#  620  gcc udp_server.c
#  621  ./a.out 172.16.4.112 8000
#  622  gcc udp_server.c -o server
#  623  ./a.out 172.16.4.112 8000
#  624  ./server 172.16.4.112 8000
#  625  ./server 8000
#  626  nano udp_server.c
#  627  nano udp_client.c
#  628  gcc udp_server.c -o server
#  629  ./server 8000
#  630  nano tcp_server.c
#  631  nano tcp_client.c
#  632  gcc tcp_server.c -o server
#  633  ./server 8000
#  634  ls
#  635  cd CN
#  636  ls
#  637  cd ass2
#  638  ls
#  639  cd q1
#  640  ls
#  641  gcc client.c -o client
#  642  ./client
#  643  nano client.c
#  644  gcc client.c -o client
#  645  nano client.c
#  646  gcc client.c -o client
#  647  ./client 8000
#  648  nano client.c
#  649  ls
#  650  cd ..
#  651  ls
#  652  cd q2
#  653  ls
#  654  cd noisy
#  655  ls
#  656  gcc sender.c -o client
#  657  ./client 172.16.4.112 8000
#  658  cd ..
#  659  ls
#  660  cd noiseless
#  661  ls
#  662  gcc sender.c -o client
#  663  ./client 172.16.4.112 8000
#  664  cd ../../ass2q3/
#  665  cd ..
#  666  ls
#  667  cd ..
#  668  ls
#  669  cd q3
#  670  ls
#  671  cd a\(Non-NACK\)/
#  672  ls
#  673  gcc client.c -o client
#  674  nano client.c
#  675  gcc client.c -o client
#  676  ./client 172.16.4.112 8000
#  677  gcc client.c -o client
#  678  ./client 172.16.4.112 8000
#  679  gcc client.c -o client
#  680  ./client 172.16.4.112 8006
#  681  ls
#  682  cd ..
#  683  ls
#  684  cd b\(NACK\)/
#  685  ls
#  686  gcc client.c -o client
#  687  ./client 172.16.4.112 8000
#  688  gcc client.c -o client
#  689  ./client 172.16.4.112 8000
#  690  l
#  691  cd ..
#  692  ls
#  693  cd c\(Piggybacked\)/
#  694  ls
#  695  gcc client.c -o client
#  696  ./client 172.16.4.112 8001
#  697  gcc client.c -o client
#  698  ./client 172.16.4.112 8001
#  699  ls
#  700  cd ..
#  701  ls
#  702  cd ..
#  703  ls
#  704  cd q4
#  705  ls
#  706  cd nack
#  707  ls
#  708  gcc client.c -o client
#  709  ./client 172.16.4.112 8006
#  710  cd ..
#  711  ls
#  712  cd non-nack/
#  713  gcc client.c -o client
#  714  ./client 172.16.4.112 9000
#  715  cd ..
#  716  ls
#  717  cd piggyback/
#  718  ls
#  719  gcc client.c -o client
#  720  ./client 172.16.4.112 9000
#  721  cd ..
#  722  ls
#  723  cd ..
#  724  ls
#  725  cd q5
#  726  ls
#  727  gcc client.c -o client
#  728  ./client 172.16.4.112 9000
#  729  ls
#  730  cd CN
#  731  ls
#  732  unzip ass2-20250501T082924Z-001.zip
#  733  ls
#  734  cd ass2
#  735  ls
#  736  cd q1
#  737  ls
#  738  gcc server.c -o server
#  739  ./server
#  740  gcc server.c -o server
#  741  ./server
#  742  nano server.c
#  743  gcc server.c -o server
#  744  ./server 8000
#  745  ls
#  746  cd ..
#  747  l
#  748  ls
#  749  cd ..
#  750  ls
#  751  cd assignment1
#  752  ls
#  753  gcc tcp_client.c -o client
#  754  ./client 172.16.4.112 8001
#  755  gcc udp_client.c -o client
#  756  ./client 172.16.4.112 8002
#  757  nano udp_client.c
#  758  nano udp_server.c
#  759  nano udp_client.c
#  760  gcc udp_client.c -o client
#  761  ./client 172.16.4.112 8003
#  762  cd ass2
#  763  ls
#  764  cd ..
#  765  ls
#  766  cd ass2
#  767  ls
#  768  cd q1
#  769  ls
#  770  nano client.c
#  771  cd ..
#  772  ls
#  773  cd q2
#  774  ls
#  775  cd noisy
#  776  ls
#  777  nano sender.c
#  778  nano reciever.c
#  779  l
#  780  ls
#  781  nano receiver.c
#  782  nano sender.c
#  783  gcc receiver.c -o server
#  784  ./server 8000
#  785  ls
#  786  rm sender
#  787  ls
#  788  cd ..
#  789  ls
#  790  cd noiseless
#  791  ls
#  792  nano sender.c
#  793  nano receiver.c
#  794  ls
#  795  gcc receiver.c -o server
#  796  ./server 8000
#  797  nano receiiver.c
#  798  ls
#  799  nano receiver.c
#  800  cd ..
#  801  ls
#  802  cd noisy
#  803  ls
#  804  nano receiver.c
#  805  cd ..
#  806  ls
#  807  cd ..
#  808  ls
#  809  cd q3
#  810  ls
#  811  cd a\(Non-NACK\)/
#  812  ls
#  813  nano server.c
#  814  ls
#  815  nano client.c
#  816  ls
#  817  gcc server.c -o server
#  818  ./server 8000
#  819  gcc server.c -o server
#  820  ./server 8000
#  821  nano server.c
#  822  gcc server.c -o server
#  823  nano server.c
#  824  gcc server.c -o server
#  825  ./server 8006
#  826  ls
#  827  cd ..
#  828  ls
#  829  cd b\(NACK\)/
#  830  ls
#  831  nano server.c
#  832  nano client.c.c
#  833  nano client.c
#  834  gcc server.c -o server
#  835  ./server 8000
#  836  gcc server.c -o server
#  837  ./server 8000
#  838  cd ..
#  839  ls
#  840  cd c\(Piggybacked\)/
#  841  ls
#  842  nano server.c
#  843  ls
#  844  nano client.c
#  845  gcc server.c -o server
#  846  ./server 8001
#  847  gcc server.c -o server
#  848  ./server 8001
#  849  cd ..
#  850  ls
#  851  cd ..
#  852  ls
#  853  cd q4
#  854  ls
#  855  mv a non-nack
#  856  ls
#  857  mv b nack
#  858  ls
#  859  mv c piggyback
#  860  ls
#  861  cd nack
#  862  ls
#  863  nano server.c
#  864  ls
#  865  nano client.c
#  866  gcc server.c -o server
#  867  ./server 8006
#  868  cd ..
#  869  ls
#  870  cd non-nack/
#  871  ls
#  872  nano server.c
#  873  nano client.c.c
#  874  nano client.c
#  875  gcc server.c -o server
#  876  ./server 9000
#  877  cd ..
#  878  ls
#  879  cd piggyback/
#  880  ls
#  881  nano server.c
#  882  nano client.c
#  883  gcc server.c -o server
#  884  ./server 9000
#  885  cd ..
#  886  ls
#  887  cd q5
#  888  ls
#  889  mv sender.c client.c
#  890  mv receiver.c server.c
#  891  nano server.
#  892  nano server.c
#  893  nano client.c
#  894  gcc server.c -o server
#  895  ./server 9000
#  896  ls
#  897  cd ..
#  898  ls
#  899  cd ..
#  900  ls
#  901  rm ass2-20250501T082924Z-001.zip
#  902  ls
#  903  rm assign1
#  904  rm -rf assign1 assign2
#  905  ls
#  906  rm raw_server.c
#  907  rm raw_client.c
#  908  ls
#  909  rm assignment2
#  910  rm -rf assignment2
#  911  ls
#  912  mv ass2 assign2
#  913  ls
#  914  mv assignment1 assign1
#  915  ls
#  916  cd CN
#  917  ls
#  918  cd assign1
#  919  cd ..
#  920  cd assign2
#  921  ls
#  922  cd q1
#  923  ls
#  924  gcc client.c -o client
#  925  ./client 172.16.4.112 9000
#  926  ls
#  927  nano server.c
#  928  nano client.c
#  929  nano server.c
#  930  gcc client.c -o client
#  931  ./client 172.16.4.112 9000
#  932  nano client.c
#  933  cd CN
#  934  ls
#  935  cd assign2
#  936  ls
#  937  cd q1
#  938  ls
#  939  gcc server.c -o server
#  940  ./server
#  941  ./server 9000
#  942  gcc server.c -o server
#  943  ./server 9000
#  944  ls
#  945  cd CN
#  946  ls
#  947  cd assign1
#  948  ls
#  949  gcc udp_server.c -o server
#  950  ./server 8000
#  951  ls
#  952  cd CN
#  953  ls
#  954  cd assign1
#  955  ls
#  956  gcc udp_client.c -o client
#  957  ./client 172.16.4.112 8000
#  958  gcc udp_client.c -o client
#  959  ./client 172.16.4.112 8000
#  960  cd ..
#  961  ls
#  962  cd assign2
#  963  ls
#  964  ls
#  965  cd CN
#  966  ls
#  967  cd assign2
#  968  ls
#  969  logout
#  970  nano env_demo.c
#  971  gcc env_demo.c -o env_demo -std=c99
#  972  gcc-std=c99 env_demo.c -o env_demo
#  973  gcc -std=c99 env_demo.c -o env_demo
#  974  nano env_demo.c
#  975  ls
#  976  rm env_demo.c
#  977  who
#  978  nano env_demo.c
#  979  gcc -std=c99 env_demo.c -o env_demo
#  980  ./env_demo
#  981  nano set_env.c
#  982  gcc set_env.c -o set_env -std=c99
#  983  nano set_env.c
#  984  gcc set_env.c -o set_env -std=c99
#  985  nano set_env.c
#  986  rm set_env.c
#  987  nano set_env.c
#  988  gcc set_env.c -o set_env -std=c99
#  989  nano set_env.c
#  990  gcc set_env.c -o set_env -std=c99
#  991  rm set_env.c
#  992  nano set_env.c
#  993  gcc set_env.c -o set_env -std=c99
#  994  ./set_env
#  995  rm set_env.c
#  996  nano set_env.c
#  997  gcc set_env.c -o set_env -std=c99
#  998  ./set_env
#  999  who
# 1000  vi A3_08_01A.sh
# 1001  ls
# 1002  cd OS
# 1003  ls
# 1004  echo "banana" > fruits.txt
# 1005  echo "apple" >> fruits.txt
# 1006  echo "cherry" >> fruits.txt
# 1007  echo "date" >> fruits.txt
# 1008  ls
# 1009  echo "banana" > fruits.txt
# 1010  echo "apple" >> fruits.txt
# 1011  echo "cherry" >> fruits.txt
# 1012  echo "date" >> fruits.txt
# 1013  clear
# 1014  ls
# 1015  sort fruits.txt
# 1016   ls
# 1017  rm fruits.txt
# 1018  echo "banana" >fruits.txt; echo "apple" >>fruits.txt; echo "cherry" >> fruits.txt; echo "date" >> fruits.txt; sort fruits.txt
# 1019  ps
# 1020  touch file1.txt; ls -l file1.txt; chmod 777 file1.txt; ls -l file1.txt
# 1021  echo "apple is red" > colors.txt; echo "banana is yellow" >> colors.txt; echo "cherry is red" >> colors.txt; echo "grape is green" >> colors.txt; grep 'red' colors.txt
# 1022  touch new_empty_file.txt; ls -l new_empty_file.txt; ls -l fruits.txt;
# 1023  sleep 5; touch fruits.txt; ls -l fruits.txt
# 1024  seq 1 50 > numbers.txt; less numbers.txt
# 1025  seq 1 5 > numbers.txt; less numbers.txt
# 1026  head numbers.txt
# 1027  head -n 3 numbers.txt
# 1028  tail -n 3 numbers.txt
# 1029  top
# 1030  sleep 300 &; jobs -l;
# 1031  sleep 300 &; jobs -l
# 1032  sleep 300 &
# 1033  jobs -l
# 1034  kill 12345 # Replace 12345 with the actual PID you noted
# 1035  history
#[1]+  Terminated              sleep 300



#31) du - It estimates file space usage (of a file or directory).

#mkdir my_data

#echo "This is some text." > my_data/fileA.txt
#head -c 1M /dev/urandom > my_data/large_file.bin
#du -h my_data/fileA.txt

#4.0K    my_data/fileA.txt
#4.0K    my_data/fileA.txt

#du -sh my_data/

#4.0K    my_data/



#32) ping - It tests network connectivity to a host.

#ping google.com

#Pinging google.com [142.250.194.46] with 32 bytes of data:
#Reply from 142.250.194.46: bytes=32 time=25ms TTL=118
#Reply from 142.250.194.46: bytes=32 time=26ms TTL=118
#Reply from 142.250.194.46: bytes=32 time=25ms TTL=118
#Reply from 142.250.194.46: bytes=32 time=26ms TTL=118
#
#Ping statistics for 142.250.194.46:
#    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
#Approximate round trip times in milli-seconds:
#    Minimum = 25ms, Maximum = 26ms, Average = 25ms



#33) wc - It counts lines, words, and characters in a file.

#echo "Line one" > sample.txt ; echo "Line two, with more words." >> sample.txt ; echo "Line three." >> sample.txt; wc sample.txt

# 3  9 48 sample.txt



#34) >/>> - It redirects the standard output of a command to a file, overwriting the file if it exists.

#echo "First line" > output.txt
#cat output.txt

#First line



#35) | - It takes the standard output of one command and uses it as the standard input for another command.

#ls -l | grep "Jul 22"

#-rw-r--r--. 1 be2303 ugyr23    59 Jul 22 17:42 colors.txt
#-rwxr-xr-x. 1 be2303 ugyr23 13024 Jul 22 17:30 env_demo.c
#-rwxrwxrwx. 1 be2303 ugyr23     0 Jul 22 17:40 file1.txt
#-rw-r--r--. 1 be2303 ugyr23    25 Jul 22 17:44 fruits.txt
#drwxr-xr-x. 2 be2303 ugyr23    23 Jul 22 17:55 my_data
#-rw-r--r--. 1 be2303 ugyr23     0 Jul 22 17:43 new_empty_file.txt
#-rw-r--r--. 1 be2303 ugyr23    10 Jul 22 17:46 numbers.txt
#-rw-r--r--. 1 be2303 ugyr23    11 Jul 22 17:58 output.txt
#-rw-r--r--. 1 be2303 ugyr23    48 Jul 22 17:57 sample.txt

#cat numbers.txt | wc -l

#5
