var n,p,now,ans:longint;
    son:array[0..400,0..400] of longint;
    g:array[0..400] of longint;
procedure init;
var i,j,x,y:longint;
begin
  assign(input,'disease.in'); reset(input);
    readln(n,p);
    for i:=1 to p do begin
      readln(x,y);
      inc(son[x,0]); son[x,son[x,0]]:=y;
      inc(son[y,0]); son[y,son[y,0]]:=x;
    end;
  close(input);
end;
procedure build(k:longint);
var i,j,t:longint;
begin
  for i:=1 to son[k,0] do begin
    t:=son[k,i];
    for j:=1 to son[t,0] do
      if son[t,j]=k then break;
    son[t,j]:=son[t,son[t,0]];
    dec(son[t,0]);
    build(t);
  end;
end;
procedure dfs(k:longint);
var i,j:longint;
    f:boolean;
begin
  if now>ans then exit;
  f:=false;
  for i:=1 to n do
    if g[i]=k then
      for j:=1 to son[i,0] do begin
        inc(now);
        g[son[i,j]]:=k+1;
        f:=true;
      end;
  dec(now);
  for i:=1 to n do
    if g[i]=k+1 then begin
      g[i]:=0;
      dfs(k+1);
      g[i]:=k+1;
    end;
  inc(now);
  for i:=1 to n do
    if g[i]=k+1 then begin
      g[i]:=0;
      dec(now);
    end;
  if not f then
    if now<ans then ans:=now;
end;
procedure main;
begin
  build(1);
  g[1]:=1;
  now:=1;
  ans:=maxlongint;
  dfs(1);
end;
procedure print;
begin
  assign(output,'disease.out'); rewrite(output);
    writeln(ans);
  close(output);
end;
begin
  init;
  main;
  print;
end.
