from __future__ import print_function
import datetime
import os.path
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build

# Scope per gestire il calendario in lettura e scrittura
SCOPES = ['https://www.googleapis.com/auth/calendar']

def get_calendar_service():
    creds = None
    if os.path.exists('token.json'):
        creds = Credentials.from_authorized_user_file('token.json', SCOPES)
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file('credentials.json', SCOPES)
            creds = flow.run_local_server(port=0)
        with open('token.json', 'w') as token:
            token.write(creds.to_json())
    return build('calendar', 'v3', credentials=creds)

def create_event():
    service = get_calendar_service()
    event = {
        'summary': 'Lezione Python CNA',
        'location': 'CNA Aula 2',
        'description': 'Automazione con Google Calendar API',
        'start': {
            'dateTime': '2025-06-20T10:00:00',
            'timeZone': 'Europe/Rome',
        },
        'end': {
            'dateTime': '2025-06-20T11:00:00',
            'timeZone': 'Europe/Rome',
        },
        'reminders': {
            'useDefault': False,
            'overrides': [
                {'method': 'email', 'minutes': 24 * 60},
                {'method': 'popup', 'minutes': 10},
            ],
        },
    }

    event = service.events().insert(calendarId='primary', body=event).execute()
    print(f"✅ Evento creato: {event.get('htmlLink')}")

if __name__ == '__main__':
    create_event()
