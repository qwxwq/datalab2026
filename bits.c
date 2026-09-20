/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~((~x)|(~y));
    return 2;
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(~x&~y)&~(x&y);
    return 2;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x&&!y)
    {
        return 1;
    }else if(!x^!y)
    {
        return 0;
    }else{
        return !(x>>31^y>>31);
    }
    return 2;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int shift1=(v>65535)<<4;
    v=v>>shift1;
    int shift2=(v>255)<<3;
    v=v>>shift2;
    int shift3=(v>15)<<2;
    v=v>>shift3;
    int shift4=(v>3)<<1;
    v=v>>shift4;
    int shift5=(v>1)<<0;
    return shift1|shift2|shift3|shift4|shift5;
    return 2;
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int byte1=n<<3;
    int byte2=m<<3;
    int byte_n=(x>>byte1)&0xFF;
    int byte_m=(x>>byte2)&0xFF;
    int mask=(0xFF<<byte1)|(0xFF<<byte2);
    x=x&~mask;
    return x|(byte_m<<byte1)|(byte_n<<byte2);
    return 2;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned int res=0;
    int i=32;
    while(i)
    {
        res=(res<<1)|(v&1);
        v=v>>1;
        i=i-1;
    }
    return res;
    return 2;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    return x>>n&~(((1<<31)>>n)<<1);
    return 2;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int num1=(!~(x>>16))<<4;
    x=x<<num1;
    int num2=(!~(x>>24))<<3;
    x=x<<num2;
    int num3=(!~(x>>28))<<2;
    x=x<<num3;
    int num4=(!~(x>>30))<<1;
    x=x<<num4;
    int num5=(!~(x>>31))<<0;
    x=x<<num5;
    int num6=(!~(x>>31))<<0;
    return num1+num2+num3+num4+num5+num6;
    return 2;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x){
    int sign=0;
    if(x==0){
        return 0;
    }
    if(x==0x80000000){
        return 0xcf000000;
    }
    if(x<0){
        sign=0x80000000;
        x=-x;
    }
    int pos=30;
    for(pos;pos>=0;pos--){
        if((x>>pos)&1){
            break;
        }
    }
    if(pos<=23){
        return sign|((pos+127)<<23)|((x<<(23-pos))&0x7fffff);
    }else{
        int shift=pos-23;
        int frac=x>>shift;
        int lost=x-(frac<<shift);
        int half=1<<(shift-1);
        if(lost>half-(frac&1)){
            frac=frac+1;
        }
        return sign|(((pos+126)<<23)+frac);
    }
}
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    int last=uf&0x7fffff;
    int mid=uf>>23&0xff;
    if(mid==0xff)
    {
        return uf;
    }else if(mid==0)
    {
        return uf&(1<<31)|uf<<1;
    }else if(mid==0xfe){
        return uf&(1<<31)|(0xff<<23);
    }else{
        return uf&(1<<31)|(mid+1)<<23|last;
    }
    return 2;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int last=uf2&0xfffff;
    int mid=(uf2>>20)&0x7ff;
    int sign=(uf2>>31)&1;
    int result;
    int e=mid-1023;
    if(e<0)
    {
        return 0;
    }else if(e>=31)
    {
        return 0x80000000;
    }else{
        if(e<=20)
        {
            result=1<<e|last>>(20-e);
        }else if(e<=30){
            result=1<<e|last<<(e-20)|uf1>>(52-e);
        }
    }
    if(sign)
    {
        return -result;
    }else{
        return result;
    }
    return 2;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x<-149)
    {
        return 0;
    }else if(x<-126){
        return 1<<(x+149);
    }else if(x<0){
        return (x+127)<<23;
    }else if(x<=127)
    {
        return (x+127)<<23;
    }else{
        return 0xff<<23;
    }
    return 2;
}

