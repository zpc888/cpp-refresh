# Object memory model
## Object Header
1. Mark Word (8 bytes)
    * HashCode
    * GC cycle 4 bits, so max 15
    * Lock Mark
    * Biased Locking
    * etc
2. Class Pointer (8 bytes)
    * -XX:+UseCompressedOops (turn on class pointer compression)
        * 4 bytes for class pointer
        * 4 bytes for padding
    * -XX:-UseCompressedOops (turn off class pointer compression)
        * 8 bytes for class pointer
3. Array Length (4 bytes, and only for array type)

## Instance Data
* 1 bytes for boolean, byte
* 2 bytes for short, char 
* 4 bytes for int, float 
* 8 bytes for long, double 
* 8 bytes for reference if not compressed, otherwise 4 bytes when compressed flag is on

## Padding (n*8 bytes)
if sum(object header + instance data) can be divided by 8, no need to pad; otherwise pad to n*8.

# Build projects
* build project

```./gradlew clean build```

* package project

```./gradlew fatJar```

* or build and package togeter

```./gradlew clean build fatJar```

# Run 
## Object
* class pointer compressed

java -XX:+UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-bytes.jar

![cp compressed](images/default-compressed-cp-for-new-obj.png)

total: 16 bytes, but last 4 bytes are purely for padding purpose since it has 12 bytes by itself, which is not 8*n
16 = 8 bytes mark word + 4 compressed class pointer + 4 padding bytes

* no class pointer compressed

java -XX:-UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-bytes.jar

![no cp compressed](images/turn-off-compressed-cp-for-new-obj.png)

total: 16 bytes, all bytes are needed, i.e. no padding bytes needed since it is 8*2.
16 = 8 bytes mark word + 8 non-compressed class pointer 

## Object Array (default length = 10, i.e. 10 class pointer or reference)
* class pointer compressed

java -XX:+UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-array-bytes.jar 10

![cp compressed](images/default-compressed-cp-for-new-obj-array-10.png)

total: 56 bytes = 8 bytes mark word + 4 compressed cp + 4 bytes array length + 10 * 4 compressed cp + 0 padding bytes

java -XX:+UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-array-bytes.jar 9

![cp compressed](images/default-compressed-cp-for-new-obj-array-9.png)

total: 56 bytes = 8 bytes mark word + 4 compressed cp + 4 bytes array length + 9 * 4 compressed cp + 4 padding bytes

* no class pointer compressed

java -XX:-UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-array-bytes.jar 10

![cp compressed](images/no-compressed-cp-for-new-obj-array-10.png)

total: 104 bytes = 8 bytes mark word + 8 cp + 4 bytes array length + 10 * 8 compressed cp + 4 padding bytes

java -XX:-UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-object-array-bytes.jar 9

![cp compressed](images/no-compressed-cp-for-new-obj-array-9.png)

total: 96 bytes = 8 bytes mark word + 8 cp + 4 bytes array length + 9 * 8 compressed cp + 4 padding bytes

## Custom Class
* class pointer compressed

java -XX:+UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-custom-bytes.jar

![cp compressed](images/default-compressed-cp-for-new-custom.png)

total: 16 bytes, but last 3 bytes are purely for padding purpose since it has 13 bytes by itself, which is not 8*n
16 = 8 bytes mark word + 4 compressed class pointer + 1 byte A.i + 3 padding bytes

* no class pointer compressed

java -XX:-UseCompressedOops -Djdk.attach.allowAttachSelf -jar build/libs/tell-new-custom-bytes.jar

![no cp compressed](images/turn-off-compressed-cp-for-new-custom.png)

total: 24 bytes = 8 bytes mark word + 8 class pointer + 1 byte A.i + 7 bytes padding
