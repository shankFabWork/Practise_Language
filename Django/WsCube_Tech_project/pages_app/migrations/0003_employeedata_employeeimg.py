# Generated by Django 3.2.5 on 2021-10-01 08:50

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pages_app', '0002_employeedata'),
    ]

    operations = [
        migrations.AddField(
            model_name='employeedata',
            name='employeeImg',
            field=models.FileField(default=None, max_length=250, null=True, upload_to='emp/'),
        ),
    ]
