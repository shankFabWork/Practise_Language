# Generated by Django 3.2.5 on 2021-10-19 13:25

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('flight_app', '0005_alter_reservation_flight'),
    ]

    operations = [
        migrations.AlterField(
            model_name='flight',
            name='flightNumber',
            field=models.CharField(max_length=10, null=True),
        ),
        migrations.AlterField(
            model_name='passenger',
            name='middleName',
            field=models.CharField(blank=True, default='', max_length=20, null=True),
        ),
    ]
