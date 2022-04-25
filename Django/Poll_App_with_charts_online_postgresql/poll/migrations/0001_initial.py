# Generated by Django 3.1.1 on 2020-09-20 06:39

import datetime
from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='CheckBox',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('text_val', models.CharField(blank=True, max_length=100)),
                ('bool_val', models.BooleanField(default=False)),
            ],
        ),
        migrations.CreateModel(
            name='RandomImage',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('img', models.ImageField(upload_to='images')),
            ],
        ),
        migrations.CreateModel(
            name='Question',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('ques_text', models.CharField(max_length=100)),
                ('pub_date', models.DateTimeField(default=datetime.datetime(2020, 9, 20, 12, 9, 1, 251337))),
                ('choice1_bool', models.BooleanField(default=False)),
                ('choice1_text', models.CharField(max_length=50)),
                ('choice1_vote', models.IntegerField(default=0)),
                ('choice2_bool', models.BooleanField(default=False)),
                ('choice2_text', models.CharField(max_length=50)),
                ('choice2_vote', models.IntegerField(default=0)),
                ('choice3_bool', models.BooleanField(default=False)),
                ('choice3_text', models.CharField(max_length=50)),
                ('choice3_vote', models.IntegerField(default=0)),
                ('choice4_bool', models.BooleanField(default=False)),
                ('choice4_text', models.CharField(max_length=50)),
                ('choice4_vote', models.IntegerField(default=0)),
                ('user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]