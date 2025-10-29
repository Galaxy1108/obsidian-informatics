const maxdepth=10;
var time,a,b,i,depth,t:longint;
    found:boolean;
    answer,d:array[0..maxdepth] of longint;
function gcd(a,b:longint):longint;
begin
  t:=a mod b;
  while t<>0 do begin
    a:=b;
    b:=t;
    t:=a mod b;
  end;
  gcd:=b;
end;
procedure dfs(a,b,k:longint);
var i,m,s,t:longint;
begin
  if k=depth+1 then exit else
    if (b mod a=0)and(b div a>d[k-1]) then begin
      d[k]:=b div a;
      if not found or(d[k]<>answer[k]) then
        answer:=d;
      found:=true;
      exit;
    end;
  s:=b div a;
  if s<d[k-1]+1 then s:=d[k-1]+1;
  t:=(depth-k+1)*b div a;
  if t>maxlongint div b then t:=maxlongint div b;
  if found and(t>=answer[depth]) then t:=answer[depth]-1;
  for i:=s to t do begin
    d[k]:=i;
    m:=gcd(i*a-b,b*i);
    dfs((i*a-b) div m,(b*i) div m,k+1);
  end;
end;
procedure init;
begin
  assign(input,'math.in'); reset(input);
    readln(a,b);
  close(input);
end;
procedure print;
var i:longint;
begin
  assign(output,'math.out'); rewrite(output);
    writeln(depth);
    for i:=1 to depth do
      write(answer[i],' ');
    writeln;
  close(output);
end;
procedure main;
begin
  found:=false; d[0]:=1;
  for depth:=1 to maxdepth do begin
    dfs(a,b,1);
    if found then begin
      print;
      break;
    end;
  end;
end;
begin
  init;
  main;
end.
