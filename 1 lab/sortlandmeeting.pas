var a:array[1..10000, 0..1] of real;
    i,j,n:integer;
    k,l:real;
begin
    assign(input, 'sortland.in');
    assign(output, 'sortland.out');
    readln(n);

    for i:=1 to n do begin
        read(a[i][0]);
        a[i][1]:=i;
    end;

    for i := 1 to n-1 do
        for j := 1 to n-i do
            if a[j][0] > a[j+1][0] then begin
                k := a[j][0];
                a[j][0] := a[j+1][0];
                a[j+1][0] := k;
                l := a[j][1];
                a[j][1] := a[j+1][1];
                a[j+1][1] := l
            end;
//for i:=1 to n do write(a[i][0],' ',a[i][1])
    write(round(a[1][1]),' ',round(a[trunc(n/2)+1][1]),' ',round(a[n][1]));
end.