from django.apps import AppConfig


class UsersConfig(AppConfig):
    DEFAULT_AUTO_FIELD = 'django.db.models.AutoField'
    name = 'users'

    def ready(self):
        import users.signals
