Program P1212;

Var
x,y:array[1..1000] of real;
link:array[1..1000,1..1000] of boolean;
match:array[1..1000] of longint;
visited:array[1..1000] of boolean;
r,a,t,ans,i,j:longint;
xx,yy,v:real;

Function matching(p:longint):boolean;
var
i:longint;
begin
for i:=1 to a do
if link[p,i] and not visited[i] then
   begin
    visited[i]:=true;
    if (match[i]=0) or matching(match[i]) then
     begin
      match[i]:=p;
      exit(true);
     end;
   end;
exit(false);
end;

Begin
readln(r,a,t);
for i:=1 to a do
read(x[i],y[i]);
for i:=1 to r do
begin
   read(xx,yy,v);
   for j:=1 to a do
    if sqrt(sqr(xx-x[j])+sqr(yy-y[j]))<=v*t then
     link[i,j]:=true;
end;
for i:=1 to r do
begin
   fillchar(visited,sizeof(visited),0);
   if matching(i) then inc(ans);
end;
writeln(ans);
End.