(*ola*)
program triangle;

const
    MSG = 'Enter the three sizes of a triangle: ';

var
    a, b, c;
    valid = 1;

begin   
    repeat
        write(MSG);
        readln(a, b, c);

        write('(', a, ', ', b, ', ', c, ') ');

        if (a + b) <= c or (a + c) <= b or (b + c) <= a then
            begin
                writeln('is an invalid triangle');
                valid := 0
            end
        else
            if a = b and b = c then
                writeln('is an equilateral triangle')
            else if a = b or a = c or b = c then
                writeln('is an isosceles triangle')
            else
                writeln('is a scalene triangle');
        writeln()
    until valid = 0
end.
