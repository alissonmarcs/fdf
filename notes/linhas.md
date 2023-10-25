## Linhas
Se você tem dois pontos que estão no mesmo x, varie o y e você terá uma reta vertical.
Se você tem dois pontos que estão no mesmo y, varie o x e você terá uma reta horizontal.

Se você tem dois pontos: p1(3, 3) e p2(10, 10), precisará variar ambos x e y dos dois valores para ter uma reta.

## bresenham's 
Ele escolhe o valor de inteiro y de acordo com o pixel que tem o centro que está mais próximo do y ideal (fracional), para o mesmo x. Em colunas sucessivas o y pode permanecer o mesmo ou aumentar 1.

## wikipedia notes
line is defined to start and end on integer coordinates

Keeping in mind that the slope is at most 1 1, the problem now presents itself as to whether the next point should be at ( x0 + 1 , y0 ) or ( x0 + 1 , y0 + 1 ).

Perhaps intuitively, the point should be chosen based upon which is closer to the line at x0 + 1. If it is closer to the former then include the former point on the line, if the latter then the latter. To answer this, evaluate the line function at the midpoint between these two points: 
