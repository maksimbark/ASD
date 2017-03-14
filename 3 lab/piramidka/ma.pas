var
a:array[1..100000] of int64;
b:array[1..100000] of int64;
n: int64;
i:integer;
procedure fix(k:integer);
var
left, right, max, temp: int64;
begin
left := 2*k;
right := 2*k+1;
max := k;
if (left <= n) AND (a[left] > a[max]) then max := left;
if (right <= n) AND (a[right] > a[max]) then max := right;
if max <> k then begin
temp:=a[k];
a[k] := a[max];
a[max] := temp;
fix(max);
end;
end;

begin
assign(input, 'sort.in');
assign(output, 'sort.out');
readln(n);
for i:=1 to n do begin
read(a[i]);
end;

for i:=round(n/2) downto 1 do fix(i);

for i:=1 to n do begin
//write(a[1], ' ');
b[i]:=a[1];
a[1] := -1000000001;
fix(1);
end;

for i:=n downto 1 do write (b[i], ' ');

end.
