load('linerA.mat')
avg = []
for i = 1:11
    avg(i) = mean(data{i}{2}.Values)
end
percent = [0 : 100]
for i = 1:11
    PercentAvgProtenB(i) = (avg(i)/3.3)*100
end
plot(percent , PercentAvgProtenB)



x = [0
10.00
20.00
30.00
40.00
50.00
60.00
70.00
80.00
90.00
100.00
];
y = [0.14
1.18
4.07
12.32
30.48
49.12
63.84
78.96
93.37
100.00
100.00
];
errorbar(x,y,0.2*y)


distance = [-4.5:0.5:4.5]


for i = 1:8
avg(i) = mean(data{i}{2}.Values)
end
for i = 1:8
B(i) = (avg(i) - 1.65) / (7.5 * (1 + 0.0012 * (25 - 25)));
end
plot(B , avg)

hold("on")
plot(B , allavg)
plot(B1 , allavgCopy)
plot(distance , avg)
plot(distance , avgCopy1)

allavg = []
for i = 1:8
allavg(i) = avg(i)
end
for i = 9:16
allavg(i) = avgCopy(i-8)
end
for i = 1:16
B(i) = (allavg(i) - 1.65) / (30 * (1 + 0.0012 * (25 - 25)));
end
plot(B , allavg)


---loadcell---
avg = []
for i = 1:10
avg(i+1) = mean(data{i}{2}.Values)
end
avg(1) = mean(data{11}{2}.Values)


avg = []
for i = 1:10
avg(i+1) = mean(data{i}{2}.Values)+0.0315
end
avg(1) = mean(data{11}{2}.Values)+0.0315
