/* 
 * CS:APP Data Lab 
 * 
 * <请在这里写上你的名字和用户ID>
 * 
 * bits.c - 源文件和你对实验室的解决方案。
 *          这是你将提交给你的老师的文件.
 *
* 警告：不要包括<stdio.h>头文件；它会使dlc混淆。
* 编译器。你仍然可以使用printf进行调试，而不必包括
* <stdio.h>，尽管你可能会得到一个编译器警告。一般来说。
* 忽略编译器的警告不是好的做法，但在这种情况下
* 但在这个例子中，它是可以的。
 */

#if 0
/*
 * 对学生的指示:
 *
 * 第1步：仔细阅读以下说明。
 */

你将通过编辑这个源文件中的函数集合向数据实验室提供你的解决方案.

整数编码规则:

  用一行或多行实现该函数的C语言代码来替换每个函数中的 "return "语句.
  你的代码必须符合以下风格:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  每个 "Expr "是一个表达式,只使用以下内容:
  1. 整数常数0到255(0xFF),包括在内.你不允许使用大的常数,如0xffffffffff.
  2. 函数参数和局部变量（没有全局变量).
  3. 单项整数操作 ! ~
  4. 二进制整数操作 & ^ | + << >>
    
  有些问题甚至进一步限制了允许的操作者的集合.
  每个 "Expr "可以由多个运算符组成. 你不被限制在每条线上只有一个操作员.

  明确禁止你:
  1. 使用任何控制结构，如if、do、while、for、switch等.
  2. 定义或使用任何宏.
  3. 在这个文件中定义任何额外的功能.
  4. 调用任何函数.
  5. 使用任何其他操作, 如 &&, ||, -, or ?:
  6. 使用任何形式的铸造. //Use any form of casting.
  7. 使用int以外的任何数据类型.这意味着你不能使用数组,结构体或联合体.

 
  你可以认为你的机器:
  1. 使用2s补码，32位的整数表示法.
  2. 进行算术上的右移.
  3. 如果移位量小于0或大于31，移位时有不可预知的行为.


可接受的编码风格的例子:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

浮点编码规则

对于需要你实现浮点运算的问题,编码规则不太严格.
你可以使用循环和条件控制.你可以使用整数和无符号.你可以使用任意的整数和无符号常量.
你可以对int或unsigned数据使用任何算术、逻辑或比较操作.

明确禁止你:
  1. 定义或使用任何宏.
  2. 在这个文件中定义任何额外的功能.
  3. 调用任何函数.
  4. 使用任何形式的铸造.
  5. 使用int或无符号以外的任何数据类型. 这意味着你不能使用数组、结构体或联合体.
  6. 使用任何浮点数据类型、操作或常量.


注意事项:
  1. 使用dlc（数据实验室检查器）编译器（在讲义中描述）来检查你的解决方案的合法性.
  2. 每个函数都有一个最大的操作数(整数、逻辑或比较),允许你在实现该函数时使用.最大操作数是由dlc检查的.
     请注意，赋值（'='）不被计算在内；你可以随意使用这些操作而不受惩罚.
  3. 使用btest测试线束来检查你的函数是否正确.
  4. 使用BDD检查器来正式验证你的函数
  5. 每个函数的最大操作数在每个函数的标题注释中给出.
     如果写的最大操作数和这个文件中的最大操作数有任何不一致,请考虑这个文件是权威的来源.

/*
 * 第2步：根据编码规则修改以下功能。
 * 
 *   重要的是.以避免评级方面的意外:
 *   1. 使用dlc编译器来检查你的解决方案是否符合 符合编码规则。
 *   2. 使用BDD检查器来正式验证你的解决方案是否产生了正确的答案。
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}
/*根据布尔代数，可以通过 ~ 和 & ，即非和与操作实现异或操作。所谓异或就是当参与运算的两个二进制数不同时结果才为1
 * 其他情况为0。C 语言中的位操作对基本类型变量进行运算就是对类型中的每一位进行位操作
 * 所以结果可以使用“非”和“与”计算不是同时为0情况和不是同时为1的情况进行位与，即~(~x&~y)&~(x&y)*/

/* 返回最小的二进制补码整数
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1 << 31;
}
//2
/* 如果是补码最大值返回1
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(((x ^ (x + 0x1)) + 0x1) | (!(~x)));
  // 只有当x为-1即0xFFFFFFFF时，~x为0，此时(x ^ (x + 0x1)) + 0x1为0，与!(~x)相与得1，再用逻辑非运算符得到1。
  // 当x为0x7FFFFFFF时，~x为1，(x ^ (x + 0x1)) + 0x1为0。
}
/* 如果所有奇数位为1则返回1
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  return !((0xAAAAAAAA & x) ^ 0xAAAAAAAA);
  // 0xAAAAAAAA的奇数位为1
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 如果0x30 <= x <= 0x39（字符'0'到'9'的ASCII码）则返回1
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return !((x ^ 0x30) >> 3) | !((x ^ 0x39) >> 1);
  // 0x30 : 110000
  // 0x39 : 111001
}
/* 实现三目运算符
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = ~(!!x) + 1;
  return (x & y) | (~x & z);
}
/* 如果x <= y返回1
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int sign = (y + ~x + 1) >> 31; // 判断y-x符号，在x,y符号都相同的情况下，如果y-x符号为负即结果为1，那么返回0
  int bitXor = (x >> 31) ^ (y >> 31); // 判断x和y符号是否相同,相同则为0
  return !!(((!sign) & (!bitXor)) | (bitXor & (x >> 31)));
  // 在符号相同的情况下,只需关注y-x的符号不为负即可。
  // 在符号不相同的情况下,只需关注x为负返回1的情况。
}
//4
/* 使用使用位级运算实现逻辑非 !
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((x|(~x+1))>>31)+1;
  // 如果x为非0数，那么(x|(~x+1))为0x80000000,右移31位为0xFFFFFFFF，加上0x1，为0
  // 如果x为0，那么0+0x1就是1
}
/* 返回用补码表示x所需的最小比特数
 * 即一个数用补码表示最少需要几位？
 * howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 本主要采用二分法
  int b16, b8, b4, b2, b1, b0;
  int sign = x >> 31; // x的符号

  x = (sign & ~x) | (~sign & x); // 若为负数，则按位取反；若为非负数，则不变

  b16 = !!(x >> 16) << 4;// 先看高16位是否含有1，若有则表示至少需要16位，所以给b16赋值为16(1 << 4 = 16)
  x =  x >> b16; // 若有1，则原数右移16位，因为上面已经确定是否至少需要16位(针对0~15)；若没有1，则b16为0，x不用移位，继续往下面判断

  b8 = !!(x >> 8) << 3; // 看剩余位的高8位是否含有1，若有则表示至少还需要8位，给b8赋值为8
  x = x >> b8; // 同理...

  b4 = !!(x >> 4) << 2;
  x = x >> b4;

  b2 = !!(x >> 2) << 1;
  x = x >> b2;

  b1 = !!(x >> 1);
  x = x >> b1;

  b0 = x;

  return b16 + b8 + b4 + b2 + b1 + b0 + 0x1; // 最后加上符号位
}
//float
/* 返回 2 * 浮点数
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   参数和结果都是以无符号int的形式传递，但它们应被解释为单精度浮点值的位级表示.
 *   当参数为NaN时，返回参数
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp = (uf & 0x7F800000) >> 23; // 取出阶码
  int sign = uf & 0x80000000;        // 取符号位
  if (exp == 0)
    return uf << 1 | sign; // 若为非规格数，直接给uf乘以2后加上符号位即可
  if (exp == 255)
    return uf; // 若为无穷大或者NaN，直接返回自身
  exp = exp + 1; // 若uf乘以2（也就是阶码加1）后变成255，则返回无穷大
  if (exp == 255)
    return (0x7F800000 | sign);
  return (exp << 23) | (uf & 0x807FFFFF); // 返回阶码加1后的原符号数
  // 浮点数有几种特殊情况：
  // 1.若exp部分全为0(exp = 0)，则是非规格化数，它是一种非常接近0的数；
  // 2.若exp部分全为1(exp = 255)，当小数部分全为0时，表示无穷大；当小数部分不为全0时，表示未初始化数据NaN；
  // 3.以上两种情况以外，就是规格化数。
  // 所以我们需要判断uf是哪一种浮点数，并根据它的类型来进行相应的操作
}
/* 将浮点数转换为整数
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   参数以无符号int形式传递，但它应被解释为单精度浮点值的位级表示.
 *   任何超出范围的东西（包括NaN和无穷大）都应该返回0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exp = ((uf & 0x7F800000) >> 23) - 127; // 计算出指数E
  int sign = uf & 0x80000000;                // 取符号位S
  int frac = ((uf & 0x007FFFFF) | 0x00800000); // 如果为规格化的值，尾数M = 1 + 小数位f

  if (exp > 30) // 因为int类型最大值2^31，2^31乘以大于1的数必然大于2^31.
    return 0x80000000; // 若原浮点数指数大于31，返回溢出值
  if (exp < 0)
    return 0; // 若浮点数小于0，则返回0
  if (exp > 8)
    frac = frac << 8 >> 23; // 如果exp > 8，<< 超过8的话会丢失数据.
  else
    frac = frac << exp >> 23; // 将小数转化为整数，<< exp 等于 乘以2^exp ,然后再右移23位.

  if (!sign)
    return frac; // 正数
  else
    return ~frac + 1; // 负数
}
/* 返回2.0^x
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   返回的无符号值应该具有与单精度浮点数2.0^x相同的位表示。
 *   如果结果太小,不能以正负值表示,则返回 0. 如果太大,则返回+INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int INF = 0xFF << 23; // 设定一个最大值，也就是阶码位置都为1 即 0x7F800000
  int exp = x + 127; // 计算阶码e
  if (exp <= 0)
    return 0; // 阶码小于等于0，则返回0
  if (exp >= 255)
    return INF;     // 阶码大于等于255，则返回INF
  return exp << 23; // exp向左移，回到标准浮点数的位置
}
