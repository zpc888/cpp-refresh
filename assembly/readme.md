# Code to for-loop: sum 1 to 10
## Intent
Test how Computer handle for-loop, while, until or do-while, do-until structure for high level langauges such as C/C++, Java, Python, etc

## Solution
At low level, cpu only provides rudimentary branch/jump instruction. Branch can only check whether a registry value is zero or greater than zero.

From high level language construct into low level instruction, a de-construction process is needed. Developers should write pseduo-code to decompose a high level language construct statement. 

```c
for (i=0; i< 10; i++) {
    s += a[i];
}
```
De-construct to:
```
loop: 
    j = i - 10;
    goto end_loop if j = 0;
    s += a[i];
    i++;
    goto loop;
end_loop:
    flush registry-value for i to memory i address;
    flush registry-value for s to memory s address;
```

## States
### Before run
* s = -1  # sum
* i = -1
* a intact
![Initial States](images/sum-1-to-10-states-before-run.png)

### After run
* s = 110
* i = 10
* a intact
![Final States](images/sum-1-to-10-states-after-run.png)

# Code to if-else: max
## Intent
Same as previous `sum 1 to 10`

## Solution
```c
max = a > b ? a : b;

// or if-else
if (a > b) {
    max = a;
} else {
    max = b;
}
```
De-construct to:
``` 
    j = a - b;
    goto then if j > 0;
    max = b;
    goto end_if;
then:
    max = a;
end_if:
    flush registry-value for max to memory max address;
```

## States
### Before run
* a = 1  
* b = 2
* max = -1
![Initial States](images/if-max-after-run-states.png)

### After run
* a = 1  
* b = 2
* max = 2
![Final States](images/if-max-after-run-states.png)

