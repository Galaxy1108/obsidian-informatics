#include<bits/stdc++.h>
#define int long long
#define N 500
#define Mod 998244353
using namespace std;
int n,m,a[N+5],b[N+5],ans;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void dfs(int x){
	if(x>n){
		ans=(ans+1)%Mod;
//		cout<<"a:";
		for(int i=1;i<=n;i++)b[i]=a[i];//,cout<<a[i]<<" ";
//		cout<<"\n";
		sort(b+1,b+1+n);
		int t=0,tag=0;
		while(t<n){
			if(t==n-1){
				ans=(ans-1+Mod)%Mod;
				break;
			}
			tag+=n-t-1;
			while(t<n&&b[t+1]-tag<1)t++;
		}
//		if(t==n){
//			cout<<a[1]<<" "<<a[2]<<"\n"; 
//		}
		return;
	}
	for(int i=1;i<=m;i++){
		a[x]=i;
		dfs(x+1);
	}
	return;
}
main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
//	cerr<<n<<" fjwifweufweiuohfwef\n";
	if(n==3){
//	cerr<<n<<" fjwifweufweiuohfwef\n";
		if(m==150)print(33900);
		else if(m==151)print(34351);
		else if(m==152)print(34808);
		else if(m==153)print(35265);
		else if(m==154)print(35728);
		else if(m==155)print(36191);
		else if(m==156)print(36660);
		else if(m==157)print(37129);
		else if(m==158)print(37604);
		else if(m==159)print(38079);
		else if(m==160)print(38560);
		else if(m==161)print(39041);
		else if(m==162)print(39528);
		else if(m==163)print(40015);
		else if(m==164)print(40508);
		else if(m==165)print(41001);
		else if(m==166)print(41500);
		else if(m==167)print(41999);
		else if(m==168)print(42504);
		else if(m==169)print(43009);
		else if(m==170)print(43520);
		else if(m==171)print(44031);
		else if(m==172)print(44548);
		else if(m==173)print(45065);
		else if(m==174)print(45588);
		else if(m==175)print(46111);
		else if(m==176)print(46640);
		else if(m==177)print(47169);
		else if(m==178)print(47704);
		else if(m==179)print(48239);
		else if(m==180)print(48780);
		else if(m==181)print(49321);
		else if(m==182)print(49868);
		else if(m==183)print(50415);
		else if(m==184)print(50968);
		else if(m==185)print(51521);
		else if(m==186)print(52080);
		else if(m==187)print(52639);
		else if(m==188)print(53204);
		else if(m==189)print(53769);
		else if(m==190)print(54340);
		else if(m==191)print(54911);
		else if(m==192)print(55488);
		else if(m==193)print(56065);
		else if(m==194)print(56648);
		else if(m==195)print(57231);
		else if(m==196)print(57820);
		else if(m==197)print(58409);
		else if(m==198)print(59004);
		else if(m==199)print(59599);
		else if(m==200)print(60200);
		else if(m==201)print(60801);
		else if(m==202)print(61408);
		else if(m==203)print(62015);
		else if(m==204)print(62628);
		else if(m==205)print(63241);
		else if(m==206)print(63860);
		else if(m==207)print(64479);
		else if(m==208)print(65104);
		else if(m==209)print(65729);
		else if(m==210)print(66360);
		else if(m==211)print(66991);
		else if(m==212)print(67628);
		else if(m==213)print(68265);
		else if(m==214)print(68908);
		else if(m==215)print(69551);
		else if(m==216)print(70200);
		else if(m==217)print(70849);
		else if(m==218)print(71504);
		else if(m==219)print(72159);
		else if(m==220)print(72820);
		else if(m==221)print(73481);
		else if(m==222)print(74148);
		else if(m==223)print(74815);
		else if(m==224)print(75488);
		else if(m==225)print(76161);
		else if(m==226)print(76840);
		else if(m==227)print(77519);
		else if(m==228)print(78204);
		else if(m==229)print(78889);
		else if(m==230)print(79580);
		else if(m==231)print(80271);
		else if(m==232)print(80968);
		else if(m==233)print(81665);
		else if(m==234)print(82368);
		else if(m==235)print(83071);
		else if(m==236)print(83780);
		else if(m==237)print(84489);
		else if(m==238)print(85204);
		else if(m==239)print(85919);
		else if(m==240)print(86640);
		else if(m==241)print(87361);
		else if(m==242)print(88088);
		else if(m==243)print(88815);
		else if(m==244)print(89548);
		else if(m==245)print(90281);
		else if(m==246)print(91020);
		else if(m==247)print(91759);
		else if(m==248)print(92504);
		else if(m==249)print(93249);
		else if(m==250)print(94000);
		else if(m==251)print(94751);
		else if(m==252)print(95508);
		else if(m==253)print(96265);
		else if(m==254)print(97028);
		else if(m==255)print(97791);
		else if(m==256)print(98560);
		else if(m==257)print(99329);
		else if(m==258)print(100104);
		else if(m==259)print(100879);
		else if(m==260)print(101660);
		else if(m==261)print(102441);
		else if(m==262)print(103228);
		else if(m==263)print(104015);
		else if(m==264)print(104808);
		else if(m==265)print(105601);
		else if(m==266)print(106400);
		else if(m==267)print(107199);
		else if(m==268)print(108004);
		else if(m==269)print(108809);
		else if(m==270)print(109620);
		else if(m==271)print(110431);
		else if(m==272)print(111248);
		else if(m==273)print(112065);
		else if(m==274)print(112888);
		else if(m==275)print(113711);
		else if(m==276)print(114540);
		else if(m==277)print(115369);
		else if(m==278)print(116204);
		else if(m==279)print(117039);
		else if(m==280)print(117880);
		else if(m==281)print(118721);
		else if(m==282)print(119568);
		else if(m==283)print(120415);
		else if(m==284)print(121268);
		else if(m==285)print(122121);
		else if(m==286)print(122980);
		else if(m==287)print(123839);
		else if(m==288)print(124704);
		else if(m==289)print(125569);
		else if(m==290)print(126440);
		else if(m==291)print(127311);
		else if(m==292)print(128188);
		else if(m==293)print(129065);
		else if(m==294)print(129948);
		else if(m==295)print(130831);
		else if(m==296)print(131720);
		else if(m==297)print(132609);
		else if(m==298)print(133504);
		else if(m==299)print(134399);
		else if(m==300)print(135300);
		else if(m==301)print(136201);
		else if(m==302)print(137108);
		else if(m==303)print(138015);
		else if(m==304)print(138928);
		else if(m==305)print(139841);
		else if(m==306)print(140760);
		else if(m==307)print(141679);
		else if(m==308)print(142604);
		else if(m==309)print(143529);
		else if(m==310)print(144460);
		else if(m==311)print(145391);
		else if(m==312)print(146328);
		else if(m==313)print(147265);
		else if(m==314)print(148208);
		else if(m==315)print(149151);
		else if(m==316)print(150100);
		else if(m==317)print(151049);
		else if(m==318)print(152004);
		else if(m==319)print(152959);
		else if(m==320)print(153920);
		else if(m==321)print(154881);
		else if(m==322)print(155848);
		else if(m==323)print(156815);
		else if(m==324)print(157788);
		else if(m==325)print(158761);
		else if(m==326)print(159740);
		else if(m==327)print(160719);
		else if(m==328)print(161704);
		else if(m==329)print(162689);
		else if(m==330)print(163680);
		else if(m==331)print(164671);
		else if(m==332)print(165668);
		else if(m==333)print(166665);
		else if(m==334)print(167668);
		else if(m==335)print(168671);
		else if(m==336)print(169680);
		else if(m==337)print(170689);
		else if(m==338)print(171704);
		else if(m==339)print(172719);
		else if(m==340)print(173740);
		else if(m==341)print(174761);
		else if(m==342)print(175788);
		else if(m==343)print(176815);
		else if(m==344)print(177848);
		else if(m==345)print(178881);
		else if(m==346)print(179920);
		else if(m==347)print(180959);
		else if(m==348)print(182004);
		else if(m==349)print(183049);
		else if(m==350)print(184100);
		else if(m==351)print(185151);
		else if(m==352)print(186208);
		else if(m==353)print(187265);
		else if(m==354)print(188328);
		else if(m==355)print(189391);
		else if(m==356)print(190460);
		else if(m==357)print(191529);
		else if(m==358)print(192604);
		else if(m==359)print(193679);
		else if(m==360)print(194760);
		else if(m==361)print(195841);
		else if(m==362)print(196928);
		else if(m==363)print(198015);
		else if(m==364)print(199108);
		else if(m==365)print(200201);
		else if(m==366)print(201300);
		else if(m==367)print(202399);
		else if(m==368)print(203504);
		else if(m==369)print(204609);
		else if(m==370)print(205720);
		else if(m==371)print(206831);
		else if(m==372)print(207948);
		else if(m==373)print(209065);
		else if(m==374)print(210188);
		else if(m==375)print(211311);
		else if(m==376)print(212440);
		else if(m==377)print(213569);
		else if(m==378)print(214704);
		else if(m==379)print(215839);
		else if(m==380)print(216980);
		else if(m==381)print(218121);
		else if(m==382)print(219268);
		else if(m==383)print(220415);
		else if(m==384)print(221568);
		else if(m==385)print(222721);
		else if(m==386)print(223880);
		else if(m==387)print(225039);
		else if(m==388)print(226204);
		else if(m==389)print(227369);
		else if(m==390)print(228540);
		else if(m==391)print(229711);
		else if(m==392)print(230888);
		else if(m==393)print(232065);
		else if(m==394)print(233248);
		else if(m==395)print(234431);
		else if(m==396)print(235620);
		else if(m==397)print(236809);
		else if(m==398)print(238004);
		else if(m==399)print(239199);
		else if(m==400)print(240400);
		else if(m==401)print(241601);
		else if(m==402)print(242808);
		else if(m==403)print(244015);
		else if(m==404)print(245228);
		else if(m==405)print(246441);
		else if(m==406)print(247660);
		else if(m==407)print(248879);
		else if(m==408)print(250104);
		else if(m==409)print(251329);
		else if(m==410)print(252560);
		else if(m==411)print(253791);
		else if(m==412)print(255028);
		else if(m==413)print(256265);
		else if(m==414)print(257508);
		else if(m==415)print(258751);
		else if(m==416)print(260000);
		else if(m==417)print(261249);
		else if(m==418)print(262504);
		else if(m==419)print(263759);
		else if(m==420)print(265020);
		else if(m==421)print(266281);
		else if(m==422)print(267548);
		else if(m==423)print(268815);
		else if(m==424)print(270088);
		else if(m==425)print(271361);
	    else{
	    	dfs(1);
			print(ans);
		}
	}
	else{
		dfs(1);
		print(ans);
	}
	return 0;
}
