# IPC
sample program of pipe, fifo , Message que
# PIPE 

 # PROC
     --> it is useful for related process that means is useful for communicat with terminal.
 # CONC
     --> it is not useful for unrelated process like between two terminal
   
# FIFO   
   # PROC
       it is useful for unrelated process like between two terminal
   # CONC 
       --> sender send the data to mutipal user so there is no mechnism to send particular usr(there is no adderess for particular receiver)
     
     
# Message queue
    --> Each user have respective key and value so we can send the data  to particualr usr.
        gcc MessageQueSender.c -o MsgSnd 
        gcc messageQueReciver.c -o Msgrcv
        
        one terminal --> ./MsgSnd <TYPE> <DATA>               another Terminal--> ./Msgrcv <Type>
        
   # ipcs -q 
           ------ Message Queues --------
         key        msqid      owner      perms      used-bytes   messages     
        0x00000005 65536      spratik    644        200          2           
     this cmd useful for figure out howmany msg are in que with his key and msgid value
     
   # ipcrm -Q key
         useful to Remove all the Msg in Msgque with Key value
   # ipcrm -q id
         useful to Remove all the Msg in Msgque with id value

         
