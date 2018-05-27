# Immutable Types in C++

## Why do immutable types matter?
According to Joe Armstrong and many other computer scientists, programming should respect the laws of mathematics and/or physics, in order to avoid possible trouble. 
Yet the simple fact of reassigning a value to a variable defies the laws of mathematics.

```
int a = 0;
//yadayadayada
a = 10;
```

Mathematically, this would be similar to 

```
a = 0 = 10
0 = 10
```

Which is false. 


## How to use them in my C++ Code?

Immutables comes as a header-file that you can easily include with the ```#include``` directive. 
The template-object that implements immutables is called "IMU". Use it like this: 

```
IMU<type> immutable_variable (constructor arguments);
IMU<type> immutable_variable (other immutable);
IMU<type> immutable_variable (mutable state, constructor arguments);
IMU<type> immutable_variable (object of type type);
IMU<type> immutable_variable (mutable state, object of type type);
```

Retrieve the value like this: 
```
    *immutable_variable;
```
It will return a mutable copy of the stored value.

Assign a value like this: 
```
    immutable_variable = LVAL
```
If the variable is locked, it will return an ```IMU <type>``` that is NOT locked and contains the assigned value, else it will return itself.

In order to lock and unlock your immutable type, use

```
    immutable_variable.lock();
    immutable_variable.unlock();
```

More functions:

```
    immutable_variable -> class_function ();
    
```


