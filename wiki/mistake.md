# message queue full  
* cause  
msgrcv wasn't handled after msgsnd  
you can check with ```ipcs -q``` 

# Deadlock 
## deadlock issue 
* cause  
class A is for storing the data.  
it uses mutex A because of multi thread environment.
class B is for action.
it uses mutex B.
class A calls class B's function in some functions.
and class B's function refers class A's value.
cross-reference happens
* improvement  
break cross-refernce 
make class A not call class B.  
make class A only store the data and not call any function in it.


# multi-thread 
## singleton concurrency issue 
* cause  
In multi thread environment,  
when two thread tries to create instance at the same time,
the issue that two instance is created might happen.
Singleton is originally intended to create only one instance.
So the issue happens.  
* improvement  
  * create instance early (lazy initiation: x)
  * use lock  

# Crash  
## double free in multi-thread  
* cause  
2 thread call i2c function as soon as power on  
i2c function uses malloc and free.  
But it didn't use mutex lock.  
So double free happened  
* improvement  
i2c function uses mutex lock.  
## memory corruption 
* It is important to find where the crash happens from crash log (call stack).
* if crash happens, the process will die. 
* So we can find the cause from the last printed log before die.
* This problem was not hard to correct but finding the cause was difficult. 
