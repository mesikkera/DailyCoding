from django.db import models


class Question(models.Model):
    # 글자수의 길이가 제한된 테스트 - CharField 사용
    subject = models.CharField(max_length=200)
    # 글자수를 제한할 수 없는 텍스트 - TextField 사용
    content = models.TextField()
    create_date = models.DateTimeField()


class Answer(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    content = models.TextField()
    create_date = models.DateTimeField()
