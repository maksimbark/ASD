var a,b:array[1..1000,1..1000] of int64;
    x,y,i,j:integer;
    max:int64;
begin
    assign(input, 'turtle.in');
    assign(output, 'turtle.out');
    readln(x,y);
// X - stroki Y - Stolbtsy
    for i:=1 to x do begin
        for j:=1 to y do begin
            read(a[i][j]);
        end;
    end;


    b[x][1]:=a[x][1];



    for  i:=2 to y do begin
        b[x][i]:=a[x][i]+b[x][i-1];
    end;

    for j:=(x-1) downto 1 do begin
        b[j][1]:=a[j][1]+b[j+1][1];
    end;

//filling


    for  i:=(x-1) downto 1 do begin
        for j:=2 to y do begin

            max:=b[i+1][j];
            if b[i][j-1]>max then max:= b[i][j-1];
            b[i][j]:=a[i][j]+max;

        end;
    end;

    writeln(b[1][y]);
end.