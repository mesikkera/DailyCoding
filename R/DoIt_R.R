install.packages("readxl")
library(readxl)

df_exam <- read_excel("/Users/mesikkera/Documents/GitHub/DailyCoding/R/Data/excel_exam.xlsx")
df_exam

mean(df_exam$math)
mean(df_exam$english)
mean(df_exam$science)

df_exam_novar <- read_excel("/Users/mesikkera/Documents/GitHub/DailyCoding/R/Data/excel_exam_novar.xlsx")
df_exam_novar

df_exam_novar <- read_excel("/Users/mesikkera/Documents/GitHub/DailyCoding/R/Data/excel_exam_novar.xlsx", col_names = F)
df_exam_novar

df_exam_sheet <- read_excel("/Users/mesikkera/Documents/GitHub/DailyCoding/R/Data/excel_exam_sheet.xlsx", sheet = 3)
df_exam_sheet

df_csv_exam <- read.csv("/Users/mesikkera/Documents/GitHub/DailyCoding/R/Data/csv_exam.csv")
