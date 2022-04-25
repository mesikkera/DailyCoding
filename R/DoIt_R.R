install.packages("readxl")
library(readxl)

df_exam <- read_excel("./Documents/GitHub/DailyCoding/R/Data/excel_exam.xlsx")
df_exam

mean(df_exam$math)
mean(df_exam$english)
mean(df_exam$science)

df_exam_novar <- read_excel("./Documents/GitHub/DailyCoding/R/Data/excel_exam_novar.xlsx")
df_exam_novar

df_exam_novar <- read_excel("./Documents/GitHub/DailyCoding/R/Data/excel_exam_novar.xlsx", col_names = F)
df_exam_novar

df_exam_sheet <- read_excel("./Documents/GitHub/DailyCoding/R/Data/excel_exam_sheet.xlsx", sheet = 3)
df_exam_sheet

df_csv_exam <- read.csv("./Documents/GitHub/DailyCoding/R/Data/csv_exam.csv")
df_csv_exam

# 데이터 프레임을 CSV파일로 저장하기
df_midterm <- data.frame(english = c(90, 80, 60, 70), 
                         math = c(50, 60, 100, 20),
                         class = c(1, 1, 2, 2))
df_midterm
write.csv(df_midterm, file = "./Documents/GitHub/DailyCoding/R/Data/df_midterm.csv")
saveRDS(df_midterm, file = "./Documents/GitHub/DailyCoding/R/Data/df_midterm.rds")

df_midterm2 <- readRDS("./Documents/GitHub/DailyCoding/R/Data/df_midterm.rds")
df_midterm2

# Chap05. 데이터 분석 기초
# 데이터 파악하기, 다루기 쉽게 수정하기

# Chap05-01. 데이터 파악하기

# head(): 데이터 앞부분 출력
# tail(): 데이터 뒷부분 출력
# View(): 뷰어 창에서 데이터 확인
# dim(): 데이터 차원 출력
# str(): 데이터 속성 출력
# summary(): 요약 통계량 출력

exam <- read.csv("./Documents/GitHub/DailyCoding/R/Data/csv_exam.csv")
head(exam)
head(exam, 10)
tail(exam)
tail(exam, 10)
View(exam)
dim(exam)
str(exam)
summary(exam)

# 출력값        통계량                      설명
# Min           최솟값(Minimum)             가장 작은 값
# 1st Qu        1사분위수(1st Quantile)     하위 25%(4분의 1) 지점에 위치하는 값
# Median        중앙값(Median)              중앙에 위치하는 값 
# Mean          평균(Mean)                  모든 값을 더해 값의 개수로 나눈 값
# 3rd Qu        3사분위수(3rd Quantile)     하위 75% (4분의 3) 지점에 위치하는 값
# Max           최댓값(Maximum)             가장 큰 값

install.packages("ggplot2")
# as.data.frame(): 데이터 속성을 데이터 프레임 형태로 바꾸는 함수
mpg <- as.data.frame(ggplot2::mpg)

head(mpg)
head(mpg, 20)
tail(mpg)
tail(mpg, 20)

View(mpg)
dim(mpg)
# 234 11
# 234행 11열

str(mpg)
?mpg

# 변수명            설명
# manufacturer      제조 회사
# displ             배기량 (displacement)
# cyl               실린더 개수 (cylinders)
# drv               구동 방식 (drive wheel)
# hwy               고속도로 연비 (highway)
# class             자동차 종류
# model             자동차 모델명
# year              생산연도
# trans             변속기 종류 (transmission)
# cty               도시 연비 (city)
# fl                연료 종류 (fuel)

summary(mpg)

# Chap05-02. 변수명 바꾸기
df_raw <- data.frame(var1 = c(1, 2, 1),
                     var2 = c(2, 3, 2))
df_raw

install.packages("dplyr")
library(dplyr)
df_new <- df_raw
df_new
df_new <- rename(df_new, v2 = var2)
df_new

mpg
head(mpg)
new_mpg <- mpg
new_mpg <- rename(new_mpg, city = cty, highway = hwy)
head(new_mpg)

# Chap05-03. 파생변수 만들기
df <- data.frame(var1 = c(4, 3, 8),
                 var2 = c(2, 6, 1))
df
df$var_sum <- df$var1 + df$var2
df
df$var_mean <- (df$var1 + df$var2)/2
df
mpg
mpg$total <- (mpg$cty + mpg$hwy)/2
head(mpg)
mean(mpg$total)
summary(mpg$total)
hist(mpg$total)
ifelse(mpg$total >= 20, "pass", "fail")
mpg$test <- ifelse(mpg$total >= 20, "pass", "fail")
head(mpg, 20)

# 빈도표: 변수의 각 값들이 몇 개씩 존재하는지, 데이터의 개수를 나타낸 표
table(mpg$test)

library(ggplot2)
qplot(mpg$test)
mpg$grade <-ifelse(mpg$total >= 30, "A", ifelse(mpg$total >= 20, "B", "C"))
head(mpg, 20)
table(mpg$grade)
qplot(mpg$grade)
mpg$grade <- ifelse(mpg$total >= 30, "A", ifelse(mpg$total >= 25, "B", ifelse(mpg$total >= 20, "C", "D")))
head(mpg, 20)
qplot(mpg$grade)

midwest <- as.data.frame(ggplot2::midwest)
library(dplyr)
library(ggplot2)

head(midwest)
?midwest

midwest <- rename(midwest, total=poptotal, asian=popasian)
midwest
midwest$percentage <- (midwest$asian/midwest$total)*100
midwest$percentage
hist(midwest$percentage)
mean(midwest$percentage)
midwest$asian_percentage <- ifelse(midwest$percentage > mean(midwest$percentage), "large", "small")
midwest$asian_percentage

table(midwest$asian_percentage)
qplot(midwest$asian_percentage)

# Chap06. 자유자재로 데이터 가공하기
# Chap06-01. 데이터 전처리 - 원하는 형태로 데이터 가공하기

# dplyr 함수
# dplyr 함수                기능
# filter()                  행 추출
# select()                  열(변수) 추출
# arrange()                 정렬
# mutate()                  변수 추가
# summarise()               통계치 산출
# group_by()                집단별로 나누기
# left_join()               데이터 합치기 (열)
# bind_row()                데이터 합치기 (행)

library(dplyr)
exam <- read.csv("./Documents/GitHub/DailyCoding/R/Data/csv_exam.csv")
exam
exam %>% filter(class == 1)
# CMD + Shift + M --> %>%
exam %>%  filter(class == 2)
exam %>% filter(class != 1)
exam %>% filter(class != 3)
exam %>% filter(math > 50)
exam %>% filter(math < 50)
exam %>% filter(english > 80)
exam %>% filter(english <= 50)
exam %>% filter(class == 1 & math >= 50)
exam %>% filter(math >= 90 | english >= 90)
exam %>% filter(class == 1 | class == 3 | class == 5)
exam %>% filter(class %in% c(1, 3, 5))
class1 <- exam %>% filter(class == 1)
class1
class2 <- exam %>% filter(class == 2)
class2
class3 <- exam %>% filter(class == 3)
class3
mean(class1$math)
mean(class2$math)
mpg
displ_4 <- mpg %>% filter(mpg$displ <= 4)
displ_5 <- mpg %>% filter(mpg$displ >= 5)
mean(displ_4$displ)
mean(displ_5$displ)
mean(displ_4$hwy)
mean(displ_5$hwy)

audi <- mpg %>% filter(mpg$manufacturer == 'audi')
toyota <- mpg %>% filter(mpg$manufacturer == 'toyota')
mean(audi$cty)
mean(toyota$cty)
hwy <- mpg %>% filter(manufacturer %in% c('chevrolet', 'ford', 'honda'))
mean(hwy$hwy)

# Chap06-3. 필요한 변수만 추출하기
# select(): 데이터에 들어있는 수 많은 변수 중 일부 변수만 추출해 활용하고자 할 때 사용

exam
library(dplyr)
exam %>% select(math)
exam %>% select(english)
exam %>% select(class, math, english)
exam %>% select(-math)
exam %>% select(-math, -english)
exam %>% filter(class == 1) %>% select(english)
exam %>% 
    filter(class == 1) %>% 
    select(english)
exam %>% 
    select(id, math) %>% 
    head

exam %>% 
    select(id, math) %>% 
    head(10)
mpg
summary(mpg)
?mpg
??mpg

mpg <- as.data.frame(ggplot2::mpg)
summary(mpg)
?mpg
mpg %>% select(class, cty)
class_cty <- mpg %>% select(class, cty)
class_cty
suv_cty <- mpg %>% filter(class == 'suv') %>% select(cty)
suv_cty
compact_cty <- mpg %>% filter(class == 'compact') %>% select(cty)
compact_cty
mean(suv_cty$cty)
mean(compact_cty$cty)

# Chap06-4. 순서대로 정렬하기
# arrange(): 데이터를 원하는 순서대로 정렬
library(dplyr)

exam %>% arrange(math)
exam %>% arrange(desc(math))
exam %>% arrange(class, math)
mpg
mpg %>% filter(mpg$manufacturer == 'audi') %>% arrange(desc(hwy)) %>% head(5)

# Chap06-5. 파생변수 추가하기
# mutate(): 기존 데이터에 파생변수를 만들어 추가

exam %>% mutate(total = math + english + science) %>% head
exam %>% mutate(total = math + english + science) %>% arrange(desc(total)) %>% head(10)

exam %>% mutate(total = math + english + science, mean = (math + english + science)/3) %>% head
exam %>% mutate(total = math + english + science, mean = (math + english + science)/3) %>% arrange(desc(total)) %>% head(10)

exam %>% 
    mutate(test = ifelse(science >= 60, "Pass", "Fail")) %>% 
    head
exam %>% 
    mutate(total = math + english + science) %>% 
    arrange(total) %>% 
    head

new_mpg <- mpg
new_mpg %>% mutate(fuel_efficiency = cty + hwy) %>% head(10)
new_mpg %>% mutate(mean_fuel_efficency = (cty+hwy)/2)
new_mpg %>% 
    mutate(mean_fuel_efficenct = (cty+hwy)/2) %>% 
    arrange(desc(mean_fuel_efficency)) %>% 
    head(3)
mpg %>% 
    mutate(mean_fuel_efficency = (cty+hwy)/2) %>% 
    arrange(desc(mean_fuel_efficency)) %>% 
    head(3)

# Chap06-06. 집단별로 요약하기
# group_by(): 집단별 평균이나 집단별 빈도처럼 각 집단을 요약한 값을 구할 때 사용

exam %>% summarise(mean_math = mean(math))
exam %>% 
    group_by(class) %>% 
    summarise(mean_math = mean(math))
exam %>% 
    group_by(class) %>% 
    summarise(mean_math = mean(math),
              sum_math = sum(math),
              median_math = median(math), 
              n = n())

# summarise()에 자주 사용하는 요약 통계량 함수
# 함수          의미
# mean()        평균
# sd()          표준편차
# sum()         합계
# median()      중앙값
# min()         최솟값
# max()         최댓값
# n()           빈도

mpg %>% 
    group_by(manufacturer, drv) %>% 
    summarise(mean_cty = mean(cty)) %>% 
    head(10)

mpg %>% 
    group_by(manufacturer) %>% 
    filter(class == "suv") %>% 
    mutate(total = (cty + hwy)/2) %>% 
    summarise(mean_total = mean(total)) %>% 
    arrange(desc(mean_total)) %>% 
    head(5)

mpg %>% 
    group_by(class) %>% 
    summarise(mean_cty = mean(cty))

mpg %>% 
    group_by(class) %>% 
    summarise(mean_cty = mean(cty)) %>% 
    arrange(desc(mean_cty))

mpg %>% 
    group_by(manufacturer) %>% 
    summarise(mean_hwy = mean(hwy)) %>% 
    arrange(desc(mean_hwy)) %>% 
    head(3)

mpg %>% 
    group_by(manufacturer) %>% 
    filter(class == "compact") %>% 
    n()