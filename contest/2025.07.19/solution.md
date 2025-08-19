# 完全平方数

> 质数，异或线性基

只考虑最终的乘积是否是完全平方数，因此可以将 $a_i$ 中的所有的平方因子除去。

同时不同的质数之间数独立的，那么对于某一个质数 $p$。在去掉所有的平方因子之后，只剩下 $p^0$ 和 $p^1$ 两种可能。如果在运算的过程之中仍然保持去除所有的平方因子，那么就是对质数的指数做异或操作。

$\le 70$ 的质数一共有 $19$ 个，因此每一个数的每一个质因子的指数对于一个 $[0,2^{19})$ 内的数。而题目所求就是有多少种子集异或和为 $0$。

先建出着 $n$ 个数对应的异或线性基，那么不在线性基内的所有元素，它们任意的线性组合得到的结果，都可以**唯一**对应一个线性基内元素的线性组合，使得最终的异或和为 $0$。

假设线性基内元素的数量为 $k$，则最终答案不在线性基内元素任选的方案数，即为 $2^{n-k}-1$，其中的 $-1$ 是要去掉所有元素都不选择的那组方案。

# 最大公约数

> 莫比乌斯反演，整除分块

对于 $a\le x\le b$，$c\le y\le d$ 的限制，可以通过差分变成 $1\le x\le a$，$1\le y\le b$ 的形式。

也就是要求 $\sum\limits_{x=1}^n\sum\limits_{y=1}^m[\gcd(x,y)=k]$，发现既然有 $\gcd(x,y)=k$，那么说明 $k|x$，$k|y$，不妨将让 $x,y$ 均除掉 $k$，也就是要求 $\sum\limits_{x=1}^{\left\lfloor\frac{n}{k}\right\rfloor}\sum\limits_{y=1}^{\left\lfloor\frac{m}{k}\right\rfloor}[\gcd(x,y)=1]$ 的值。

$$\begin{aligned}\sum\limits_{i=1}^n\sum\limits_{j=1}^m[\gcd(i,j)=1]&=\sum\limits_{d=1}^{\min(n,m)}\mu(d)\sum\limits_{i=1}^n\sum\limits_{j=1}^m[d|i\land d|j]\\&=\sum\limits_{d=1}^{\min(n,m)}\mu(d)\sum\limits_{i=1}^{\left\lfloor\frac{n}{d}\right\rfloor}\sum\limits_{j=1}^{\left\lfloor\frac{m}{d}\right\rfloor}1\\&=\sum\limits_{d=1}^{\min(n,m)}\mu(d)\left\lfloor\dfrac{n}{d}\right\rfloor\left\lfloor\dfrac{m}{d}\right\rfloor\end{aligned}$$

预处理出 $\mu(d)$ 的前缀和，最终得到的式子可以通过整除分块快速求解。

时间复杂度 $O(n\sqrt{\min(b,d)})$。

# 组合数

> 组合数，斯特林数，下降幂

对于多项式 $f(k)$，肯定是要尝试将其拆开的。也就是单独考虑 $k^a$ 的问题。

但是 $k^a$ 和 $\dbinom{n}{k}$ 这个组合数并不搭，所以考虑找到和 $\dbinom{n}{k}$ 更搭配的形式：下降幂。

考虑如何求解：$\sum\limits_{k=0}^nk^{\underline{i}}x^k\dbinom{n}{k}$。

$$\begin{aligned}\sum\limits_{k=0}^nk^{\underline{i}}x^k\dbinom{n}{k}&=i!\sum\limits_{k=0}^nx^k\dbinom{k}{i}\dbinom{n}{k}\\&=i!\sum\limits_{k=0}^nx^k\dbinom{n}{i}\dbinom{n-i}{k-i}\\&=n^{\underline{i}}x^i\sum\limits_{k=i}^{n}\dbinom{n-i}{k-i}x^{k-1}\\&=n^{\underline{i}}x^i(x+1)^{n-i}\end{aligned}$$

加入 $f(x)=\sum\limits_{i=0}^mb_ix^{\underline{i}}$，那么就有 $\text{原式}=\sum\limits_{i=0}^mb_in^{\underline{i}}x^i(x+1)^{n-i}$。

现在唯一的问题就是 $b_i$ 的值为多少。

根据下降幂转普通幂：$x^n=\sum\limits_{i=0}^n\begin{Bmatrix}n\\i\end{Bmatrix}x^{\underline{i}}$。

$\begin{aligned}f(x)&=\sum\limits_{i=0}^ma_ix^i\\&=\sum\limits_{i=0}^ma_i\sum\limits_{j=0}^i\begin{Bmatrix}i\\j\end{Bmatrix}x^{\underline{j}}\\&=\sum\limits_{i=0}^mx^{\underline{i}}\sum\limits_{j=i}\begin{Bmatrix}j\\i\end{Bmatrix}a_j\end{aligned}$

也就是 $b_i=\sum\limits_{j=i}^m\begin{Bmatrix}j\\i\end{Bmatrix}a_j$。

$O(m^2)$ 预处理斯特林数以及求解 $b_i$，后面的式子 $O(m\log n)$ 计算。总时间复杂度 $O(m^2)$。

# 最小公倍数

> gcd-lcm 容斥（min-max 容斥），欧拉定理，数论分块

>  为了方便表示，在部分位置将用 $\operatorname{pow}(a,b)$ 来代替 $a^b$。

记 $S=\{1,2,3,\dots K\}$，发现 $\operatorname{lcm}$ 并不是什么好求的东西，所以考虑转成 $\gcd$ 取处理：

$$\begin{aligned}\prod\limits_{i_1,i_2\dots i_K\in [1,N]}\operatorname{lcm}(i_1,i_2\dots i_K)&=\prod\limits_{i_1,i_2\dots i_K\in [1,N]}\prod\limits_{T\subseteq S}\gcd\limits_{j\in T}(i_j)^{(-1)^{|T|-1}}\\&=\prod\limits_{T\subseteq S}\operatorname{pow}(\prod\limits_{i_1,i_2\dots i_{|T|}\in [1,N]}\gcd\limits_{j=1}^N(i_j)^{(-1)^{|T|-1}},N^{K-|T|})\end{aligned}$$

先考虑后面的一部分怎么求解，也就是：$\prod\limits_{i_1,i_2\dots i_t\in [1,N]}\gcd(i_1,i_2\dots i_t)$。

$$\begin{aligned}\prod\limits_{i_1,i_2\dots i_t\in [1,N]}\gcd(i_1,i_2\dots i_t)&=\prod\limits_{k=1}^N\operatorname{pow}(k,{\sum\limits_{i_1,i_2\dots i_t\in [1,N]}[\gcd(i_1,i_2\dots i_n)=k]})\\&=\prod\limits_{k=1}^N\operatorname{pow}(k,\sum\limits_{d=1}^{\left\lfloor\frac{N}{k}\right\rfloor}\mu(d)\left\lfloor\frac{N}{kd}\right\rfloor^t)\\&=\prod\limits_{k=1}^N\prod\limits_{d=1}^{\left\lfloor\frac{N}{k}\right\rfloor}\operatorname{pow}(k,\mu(d)\left\lfloor\frac{N}{kd}\right\rfloor^t)\\&=\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},\left\lfloor\frac{N}{D}\right\rfloor^t)\end{aligned}$$

现在将这一部分代回原式。

$$\begin{aligned}\text{原式}&=\prod\limits_{T\subseteq S}\operatorname{pow}(\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},\left\lfloor\frac{N}{D}\right\rfloor^{|T|})^{(-1)^{|T|-1}},N^{K-|T|})\\&=\prod\limits_{T\in S}^N\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},\left\lfloor\frac{N}{D}\right\rfloor^{|T|}\times (-1)^{|T|-1}\times N^{K-|T|})\\&=\prod\limits_{i=1}^N\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},\left\lfloor\frac{N}{D}\right\rfloor^{i}\times (-1)^{i-1}\times N^{K-i}\times \dbinom{N}{i})\\&=\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},\sum\limits_{i=1}^N\left\lfloor\frac{N}{D}\right\rfloor^{i}\times (-1)^{i-1}\times N^{K-i}\times \dbinom{N}{i})\end{aligned}$$

将指数的部分单独拿出来看一下：

$$\begin{aligned}\sum\limits_{i=1}^N\left\lfloor\frac{N}{D}\right\rfloor^{i}\times (-1)^{i-1}\times N^{K-i}\times \dbinom{N}{i}&=N^K-\sum\limits_{i=0}^N\dbinom{N}{i}N^{K-i}\times \left(-\left\lfloor\dfrac{N}{D}\right\rfloor\right)^i\\&=N^K-\left(N-\left\lfloor\frac{N}{D}\right\rfloor\right)^K\end{aligned}$$

将这一部分代回原式：

$$\text{原式}=\prod\limits_{D=1}^N\operatorname{pow}(\prod\limits_{d|D}d^{\mu(\frac{D}{d})},N^K-(N-\left\lfloor\frac{N}{D}\right\rfloor)^K)$$

对于 $D=1,2\dots N$ 的所有 $\prod\limits_{d|D}d^{\mu(\frac{D}{d})}$ 及其前缀积，可以直接通过枚举因子预处理，时间复杂度 $O(N\log N)$。

求积式可以通过数论分块来求解，时间复杂度 $O(\sqrt{N}\log {Mod})$。

由于答案对 $Mod=998244353$ 取模，而 $K$ 仅在指数的指数上出现，则根据欧拉定理，可以令其对 $P=\varphi(\varphi(998244353))=3\times 2^{27}$ 进行一定的处理：

如果 $K\le P$，不做修改；如果 $K>P$，令 $K\gets (K\bmod P)+P$。

总时间复杂度 $O(N\log N+T\sqrt{N}\log Mod)$。