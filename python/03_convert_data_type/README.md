# Read binary file
Binary file is useful when you want to save the file size.  
Let's read binary file generated by c lang by python program.

## generate binary file using c lang
```
./build.sh
```

c program, "main", generates binary file test.bin.  
This file contains following three data in this order.

```main.c
int num = 900;
double d = 7.85;
char str[] = "abc";
```
The data above is written in the file as follows:

```main.c
fwrite( &num, sizeof(num), 1, fp );
fwrite( &d, sizeof(d), 1, fp );
fwrite( str, sizeof(str[0]), sizeof(str), fp );
```
## read the binary file with python
sample.py reads the binary file "test.bin" as follows:

1. open the file.  
```
infile = open('test.bin', 'r')
```  
2. get the data type ,its order and the number of data.  
For example, when the data is 'abc', then data type is 'c' for `char` and the number of data is 3.
```
dataFormat=['i','d','c']
data2=struct.unpack(df*dn,data)
```  
3. move the pointer in the file, and read the data there.
```
# for example, df is 'i' (=integer)
# f.read(byteSize)
# the byte of each data type can be obtained by struct.calcsize()
for df,dn in zip(dataFormat,dataNumber):
    data = infile.read(struct.calcsize(df))
```
4. Since the data is string format, convert the binary data into the aimed format.
```
for df,dn in zip(dataFormat,dataNumber):
    data = infile.read(struct.calcsize(df))
    data2=struct.unpack(df*dn,data)
```




