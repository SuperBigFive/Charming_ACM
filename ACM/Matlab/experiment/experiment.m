clear, clc
load data_customer.txt

%% ���ݶ���
x = data_customer (:, 1);
y = data_customer (:, 2);
plot (x, y, 'c.')
%% %% %% %% %% %%%

%% ���Ƶ�һ���������
p = polyfit (x, y, 1);
yy = polyval (p, x);
hold on
plot (x, yy ,'b-')

x1 = [];
y1 = [];
x2 = [];
y2 = [];
%% %% %% %% %% %%%

%% ���Ƶڶ������������
for i =1 : 1000
    if y(i) > yy(i) && x(i) <= 114.4
        y2 = [y2; y(i)];
        x2 = [x2; x(i)];
    end
    if y(i) <= yy(i) && x(i) <= 114.4
        y1 = [y1; y(i)];
        x1 = [x1; x(i)];
    end
end

p = polyfit (x1, y1, 1);
y1 = polyval (p, x1);
hold on 
plot (x1, y1, 'b-')

f1 = @(x) (p(2) + p(1)*x);

p = polyfit (x2, y2, 1);
y2 = polyval (p, x2);
hold on 
plot (x2, y2, 'b-')

f2 = @(x) (p(2) + p(1)*x);
%% %% %% %% %% %%%

%% ���ֲ���������
accept_scale = 0.13;
up_x = zeros (1, 5);
up_y = zeros (1, 5);
down_x = zeros (1, 5);
down_y = zeros (1, 5);
key_point = zeros(2, 10);
mmin = inf;
tmp_min = inf;
ans_point = zeros (2, 10);
cnt = zeros (1,10);
cntt = 500000;
%% %% %% %% %% %%%

%% ��Ҫ����
for k = 1 : cntt
    dis_sum = 0;
    %% ���Ͷ�㣨��������ܽ�. �Ż�1��
    for i = 1 : 5
        while 1
            flag = 0;
            up_x(i) = 114.0 +(rand()-0.5)* 0.75;
            up_y(i) = f1(up_x(i)) + (rand()-0.5)* 2 * accept_scale;
            for j = 1 : 2*(i - 1)
                 dis = (key_point(1, j) - up_x(i))^2 + (key_point(2,j) - up_y(i))^2; 
                 if dis <= 0.005
                     flag = 1;
                     break;
                 end
            end
            if flag ~= 1 
                break;
            end
        end
        key_point(1, 2*i-1) = up_x(i);
        key_point(2, 2*i-1) = up_y(i);
        
        while 1
            flag = 0;
            down_x(i) =114.0 + (rand()-0.5)* 0.75;
            down_y(i) = f2(down_x(i)) + (rand()-0.5)* 2 * accept_scale;%%���ģ��Ͷ��
            for j = 1 : 2*(i - 1) + 1
                 dis = (key_point(1, j) - down_x(i))^2 + (key_point(2,j) - down_y(i))^2; 
                 if dis <= 0.005
                     flag = 1;
                     break;
                 end
            end
            if flag ~= 1 
                break;
            end
        end
        key_point(1, 2*i) = down_x(i);
        key_point(2, 2*i) = down_y(i);
    end
    %% %% %% %% %% %%%
    
    for i = 1 : 10
        cnt(i) = 0;
    end
    %% �ӹ˿�1ö�ٵ��˿�1000
    for i = 1 : 1000
        tmp_min = inf;
        %% �ҵ���˿�i�����Ͷ�ŵ�
        for j = 1 : 10
            dis = (key_point(1, j) - x(i))^2 + (key_point(2,j) - y(i))^2;
            if tmp_min > dis
                tmp_min = dis;
                tmp_bl = j;
            end
        end
        cnt(tmp_bl) = cnt(tmp_bl) + 1;
        dis_sum = dis_sum + tmp_min;
    end
    %% �����ǰÿ���˿;�����������ĵ�ľ����
    %% ��֮ǰ�õ��ĸ�С������´�
    if dis_sum < mmin 
        for j = 1 : 10
            flag = 0;
            %% �Ż�2����ֹĳ������䵽�Ĺ˿�̫�ٵ����
            if cnt(j) < 30
                flag = 1;
                break;
            end
        end
        if flag ~= 1 
            ans_point = key_point;
            mmin = dis_sum;
        end
        if flag == 1
            cntt = cntt + 1;
        end
    end
end

bl = zeros (1000, 1);
%% �õ�ÿ���˿͹����ķ���
for i = 1 : 1000
    tmp_min = inf;
     for j = 1 : 10
            dis = (key_point(1, j) - x(i))^2 + (key_point(2,j) - y(i))^2;
            if tmp_min > dis
                tmp_min = dis;
                bl(i) = j;
            end
     end
end

hold on
plot (ans_point (1,:), ans_point (2,:), 'rx')
