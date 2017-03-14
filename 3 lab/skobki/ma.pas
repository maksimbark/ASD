var
a:string;
arr:array[1..10000] of char;
n,i:integer;
begin
assign(input, 'brackets.in');
assign(output, 'brackets.out');
for i:=1 to 10000 do arr[i]:='x';
while (not eof(input)) do begin
readln (a);
n:=0;
for i:=1 to length(a) do begin
n:=n+1;
arr[n] := a[i];
if (n > 1) then
begin
if (((arr[n] = ']') and (arr[n-1] = '[')) or ((arr[n] = ')') and (arr[n-1] = '('))) then
begin
arr[n-1]:='x';
arr[n]:='x';
n := n-2;
end;

end;
end;
if n = 0 then writeln('YES') else writeln('NO');
end;

end.
