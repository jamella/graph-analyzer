from django.contrib import admin
from options.models import Option, PendingFile, SystemInfo, RecentFile, Feedback

class SystemInfoAdmin(admin.ModelAdmin):
    list_display = ("version", "status", "error", "progress", "exploits_num", "samples_num")

class OptionAdmin(admin.ModelAdmin):
    list_display = ("output_dest", "log_level", "log_file")

class PendingFileAdmin(admin.ModelAdmin):
    list_display = ("name",)

class RecentFileAdmin(admin.ModelAdmin):
    list_display = ("name",)

class FeedbackAdmin(admin.ModelAdmin):
    list_display = ("type", "description", "status")
    ordering = ("-type", "-status")

admin.site.register(SystemInfo, SystemInfoAdmin)
admin.site.register(Option, OptionAdmin)
admin.site.register(PendingFile, PendingFileAdmin)
admin.site.register(RecentFile, RecentFileAdmin)
admin.site.register(Feedback, FeedbackAdmin)