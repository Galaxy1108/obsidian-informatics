var n:longint;
    d:array[0..100] of longint;
    c:array[0..100] of string;
    b:boolean;
procedure init;
var i:longint;
begin
  assign(input,'flower.in'); reset(input);
    readln(n);
    for i:=1 to n do readln(c[i]);
  close(input);
end;
procedure print;
var i:longint;
begin
  assign(output,'flower.out'); rewrite(output);
    for i:=1 to 2*n do writeln(c[d[i]]);
    b:=true;
  close(output);
end;
procedure dfs(i:longint);
var j:longint;
begin
  if i=0 then begin
    print;
    halt;
  end;
  for j:=1 to 2*n-i-1 do begin
    if (d[j]=0)and(d[j+i+1]=0) then begin
      d[j]:=i; d[j+i+1]:=i;
      dfs(i-1);
      d[j]:=0; d[j+i+1]:=0;
    end;
  end;
end;
begin
  init;
  dfs(n);
end.
