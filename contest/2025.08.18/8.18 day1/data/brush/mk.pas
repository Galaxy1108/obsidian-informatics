program mk;
const n = 10;
      m = 10;
var i : integer;
begin
  assign(output, 'brush1.in');
  rewrite(output);
  writeln(n, random(m));
  for i := 1 to n do
   write(random(10000), ' ');
  close(output);
end.