var a:array[1..10000] of int64;
    i,j,n,k:integer;
begin
    assign(input, 'smallsort.in');
    assign(output, 'smallsort.out');
    readln(n);

    for i:=1 to n do read(a[i]);

    for i := 1 to n-1 do
        for j := 1 to n-i do
            if a[j] > a[j+1] then begin
                k := a[j];
                a[j] := a[j+1];
                a[j+1] := k
            end;
    for i:=1 to n do write(a[i],' ');
end.