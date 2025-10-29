var d:array[0..40] of longint;
    s:array[0..40] of string;
    inf,ouf,log,std:string;
    n,oo:longint;
    bool:boolean;
procedure ininf;
var i,j:longint;
begin
  assign(input,inf); reset(input);
    readln(n);
    for i:=1 to n do readln(s[i]);
  close(input);
end;
procedure inouf;
var i,j:longint;
    t:string;
begin
  assign(input,ouf); reset(input);
    for i:=1 to 2*n do begin
      readln(t);
      for j:=1 to n do
        if t=s[j] then begin
          if d[j]=0 then d[j]:=i
                    else d[j]:=abs(i-d[j]-1);
        end;
    end;
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
var i:longint;
begin
  inf:=paramstr(1);
  ouf:=paramstr(2);
  std:=paramstr(3);
  log:=paramstr(4);
  ininf;
  inouf;
  bool:=true;
  for i:=1 to n do
    if d[i]<>i then begin
      bool:=false;
      inc(oo)
    end;
end;
begin
  main;
  print;
end.
