clear
clc
disp('������ϰ1')
a=[40,20,30;30,10,50]
b=[400;300;500]
c=a*b
sprintf('��һ���Ȳ�Ʒ����=%d',c(1))
sprintf('�ڶ����Ȳ�Ʒ����=%d',c(2))

clear
disp('������ϰ2')
A=[-1 -1;1 1;]
B=[-2 2;2 -1]
A*B
B*A

clear
disp('������ϰ3')
A=rand(5,5)
B=rand(5,5)
if (A*B)'==B'*A'
    disp('��ʽ����')
else
    disp('��ʽ������')
end

clear
disp('������ϰ4')
linspace(-1,100,100)

clear
disp('������ϰ5')
A=ones(100,20)
B=zeros(100,50)
C=[A,B]

clear
disp('������ϰ6')
A=ones(100,20)
A(:,[17,19])=[]
A

clear
disp('������ϰ7')
n=input('������һ������n:')
a=rand(1,n)
s=0
for i=1:n
    s=s+a(i)*a(i)
end
if mod(n,2)
    s=s-a(n)*a(n)
else
end

clear
disp('������ϰ8')
A=rand(20,20)
B=A\eye(20,20)

clear
disp('������ϰ9')
sprintf('%s%d%s%d','���ӿƼ���ѧ-',985,'-',211)

clear
disp('������ϰ10')
A=[-1,-1;1,1]
sum(A,1)
sum(A,2)
sum(sum(A,1))
disp('over')