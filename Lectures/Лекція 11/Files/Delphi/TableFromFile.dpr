program TableFromFile;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

var f:file of real;
    x,y:real;
    i: integer;
begin
  assignFile(f,'..\..\..\Files\table.dat'); reset(f);
  writeln('     x   |     sin');
  writeln('----------------------');
  while not eof(f) do
  begin
    read(f,x,y);
    writeln(x:6:1,'   |',y:12:6)
  end;
  closeFile(f);
  readln
end.
