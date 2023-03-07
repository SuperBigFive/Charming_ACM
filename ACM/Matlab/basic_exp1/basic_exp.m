disp('2022.4.11����ʵ����ҵ�е�matlabϰ��')
n=input('������һ�����֣��������鿴���):');
switch n
    case 1
        %% ��Ŀ1 ����ֵ
        clear;clc
        format long 
        v=linspace(55,97,100);
        w=[];
        for i=100:-1:1
            w=[w,v(i)];
        end
        w=reshape(w,20,5)
    case 2
        %% ��Ŀ2 ѭ����ֵ
        clear;clc
         format short g
         format long g
        x(1)=0;
        x(2)=1;
        for i=3:40
            x(i)=x(i-1)+2*x(i-2);
        end
        x=reshape(x,10,4)
        
    case 3
        %% ��Ŀ3 ѭ�������ö�ٷ�
        %function [a,b]= question_3()
        clear;clc
        k=1;
        for i=1:1000
            t=(i*i-i)/100;
            if fix(t)==t&&t<=1000&&t>=1
                a(k)=i;
                b(k)=t;
                k=k+1;
            end
        end
        a
        b
        %end
        %����ע�͵�������matlab����
    case 4
        %% ��Ŀ4 (1) ���ƹ�Ʊ��������ͼ
        clear;clc
        load SH600004.mat
        x=[1:100]';
        y=M(end-99:end,5);
        subplot(1,2,1)
        plot(x,y,'-*');
        
    case 5
        %% ��Ŀ4 (2)�Ƿ��仯���ߺ�ɢ��ͼ
        y=zeros(1,100);
        for i=100:-1:1
            y(101-i)=(M(end-i,5)-M(end-i-1,5))/M(end-i,5);
        end
        x=1:100;
        subplot(1,2,2)
        plot(x,y,'-*r');
        bar(x,y,'r');
        
    case 6
        %% 1.2 �ۺ�ѵ��
        clear;clc
        len = 1200;
        method=[64,85];
        max_1=fix(len/method(1));
        max_2=fix(len/method(2));
        cnt=0;
        for i=0:max_1
            j=fix((len-i*method(1))/85);
            if  i + j==0
                continue
            end
            if  i*method(1) + j*method(2) > 1200 
                break
            end
            cnt=cnt+1;
            rest=1200-i*method(1) - j*method(2) ;
            mat_info(cnt,1)=i;
            mat_info(cnt,2)=j;
            mat_info(cnt,3)=rest;
        end
        disp('�иʽ��Ϣ����:');
        output=[];
        for i=1:cnt
            output=char(output,sprintf('64cm����:%d,85cm����:%d,���ϳ���:%d',mat_info(i,1),mat_info(i,2),mat_info(i,3)));
        end
        output=char(output,sprintf('�иʽ����:%d',cnt))
end