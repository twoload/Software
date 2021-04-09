# lock_guard vs unique_lock  

http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html  
1. std::lock_guard  
    * only the destructor unlocks the mutex  
2. std::unique_lock  
    * we can lock/unlock the mutex  
    * When to use  
        * std::condition_variable  

# mutex vs recursive mutex  
http://www.cplusplus.com/reference/mutex/recursive_mutex/  
https://stackoverflow.com/questions/2415082/when-to-use-recursive-mutex
* This allows to lock (or try-lock) the mutex object from a thread that is already locking it  
* for example, function that calls it recursively  

