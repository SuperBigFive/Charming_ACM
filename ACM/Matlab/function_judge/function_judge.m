%% ���ȡֵ
x=fix(randn(1,6)*10)
y=fix(randn(1,6)*10)
xy=fix(randn(1,12)*10)
input=[6,6,6,x,y,xy]

%% ˫�亯��
x=fix(randn(1,6)*10)
y=fix(randn(1,6)*10)
input=[6,6,6,x,y,x,y]

%% ���亯����������
x=fix(randn(1,6)*10)
y=fix(randn(1,7)*10)
input=[6,7,6,x,y,x,y(1:6)]

%% ���亯�����ǵ���
x=fix(randn(1,7)*10)
y=fix(randn(1,6)*10)
input=[7,6,7,x,y,x,y,fix(randn(1,1)*10)]
