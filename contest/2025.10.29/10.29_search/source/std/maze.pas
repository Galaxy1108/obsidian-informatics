const step:array[1..4,1..2] of longint=((1,0),(0,1),(-1,0),(0,-1));
var n,m,x,y,r,all,s:longint;
    g,d:array[0..100,0..100] of longint;
    path:array[0..1000] of longint;
procedure init;
var i,j:longint;
begin
  assign(input,'maze.in'); reset(input);
    readln(n,m,x,y);
    for i:=1 to n do begin
      for j:=1 to m do
        read(g[i,j]);
      readln;
    end;
  close(input);
end;
procedure dynamic;
var i,j,k,x,y:longint;
    b:boolean;
begin
  for i:=1 to n do
    for j:=1 to m do
      d[i,j]:=10000000;
  d[1,1]:=0;
  repeat
    b:=true;
    for i:=1 to n do
      for j:=1 to m do
        for k:=1 to 4 do begin
          x:=i+step[k,1]; y:=j+step[k,2];
          if (1<=x)and(x<=n)and(1<=y)and(y<=m) then
            if (g[x,y]=0)and(g[i,j]=0) then
              if (d[x,y]>d[i,j]+1) then begin
                d[x,y]:=d[i,j]+1;
                b:=false;
              end;
        end;
  until b;
end;
procedure dfs(u,v:longint);
var i,j,k:longint;
begin
  if abs(d[x,y]-d[u,v])>r then exit;
  if (u=x)and(v=y) then begin
    inc(all); exit;
  end;
  for i:=1 to 4 do begin
    j:=u+step[i,1]; k:=v+step[i,2];
    if (1<=j)and(j<=n)and(1<=k)and(k<=m) then
      if (abs(d[x,y]-d[j,k])<abs(d[x,y]-d[u,v]))and(g[j,k]=0)and(g[u,v]=0) then begin
        g[u,v]:=1; inc(s); path[s]:=i;
        dfs(j,k);
        g[u,v]:=0; dec(s);
      end;
  end;
end;
procedure main;
begin
  dynamic;
  r:=abs(d[x,y]-d[1,1]);
  dfs(1,1);
end;
begin
  assign(output,'maze.out'); rewrite(output);
    init;
    main;
    writeln(all);
  close(output);
end.
