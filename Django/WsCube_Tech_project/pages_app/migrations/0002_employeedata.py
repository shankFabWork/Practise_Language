# Generated by Django 3.2.5 on 2021-10-01 08:12

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pages_app', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='EmployeeData',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('age', models.IntegerField()),
            ],
        ),
    ]
