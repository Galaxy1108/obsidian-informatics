var d:array[0..4000] of longint;
    inf,ouf,log,std:string;
    n,a,b,ya:longint;
    bool:boolean;
    x,y,w:int64;
function gcd(a,b:int64):int64;
var t:int64;
begin
  t:=a mod b;
  while t<>0 do begin
    a:=b;
    b:=t;
    t:=a mod b;
  end;
  gcd:=b;
end;
procedure ininf;
var i,j:longint;
begin
  assign(input,inf); reset(input);
    readln(a,b);
    w:=gcd(a,b);
    a:=a div w; b:=b div w;
  close(input);
end;
procedure inouf;
var i,j:longint;
    t:string;
begin
  assign(input,ouf); reset(input);
    readln(ya);
    for i:=1 to ya do read(d[i]);
  close(input);
end;
procedure instd;
begin
  assign(input,std); reset(input);
    readln(n);
  close(input);
end;
procedure print;
begin
  assign(output,log); rewrite(output);
    if bool then writeln(1) else writeln(0);
  close(output);
  halt;
end;
procedure main;
var i,j:longint;
    u:int64;
begin
  inf:=paramstr(1);
  ouf:=paramstr(2);
  std:=paramstr(3);
  log:=paramstr(4);
  ininf;
  inouf;
  instd;
  bool:=false;
  if ya=n then begin
    for i:=1 to n do
      for j:=1 to n do
        if (i<>j)and(d[i]=d[j]) then exit;
    x:=0; y:=1;
    for i:=1 to n do begin
      y:=y*d[i]; u:=1;
      for j:=1 to n do
        if i<>j then u:=u*d[j];
      x:=x+u;
    end;
    w:=gcd(x,y);
    x:=x div w; y:=y div w;
    if (x=a)and(y=b) then bool:=true;
  end;
end;
begin
  main;
  print;
end.
