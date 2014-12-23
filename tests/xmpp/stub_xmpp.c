#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "xmpp/xmpp.h"

// connection functions
void jabber_init(const int disable_tls) {}

jabber_conn_status_t jabber_connect_with_details(const char * const jid,
    const char * const passwd, const char * const altdomain, const int port)
{
    return JABBER_CONNECTED;
}

jabber_conn_status_t jabber_connect_with_account(const ProfAccount * const account)
{
    return JABBER_CONNECTED;
}

void jabber_disconnect(void) {}
void jabber_shutdown(void) {}
void jabber_process_events(void) {}
const char * jabber_get_fulljid(void)
{
    return NULL;
}

const char * jabber_get_domain(void)
{
    return NULL;
}

jabber_conn_status_t jabber_get_connection_status(void)
{
    return (jabber_conn_status_t)mock();
}

char* jabber_get_presence_message(void)
{
    return NULL;
}

char* jabber_get_account_name(void)
{
    return (char*)mock();
}

GList * jabber_get_available_resources(void)
{
    return NULL;
}

// message functions
void message_send_chat(const char * const barejid, const char * const msg) {}
void message_send_private(const char * const fulljid, const char * const msg) {}
void message_send_groupchat(const char * const roomjid, const char * const msg) {}
void message_send_groupchat_subject(const char * const roomjid, const char * const subject) {}

void message_send_inactive(const char * const barejid) {}
void message_send_composing(const char * const barejid) {}
void message_send_paused(const char * const barejid) {}
void message_send_gone(const char * const barejid) {}

void message_send_invite(const char * const room, const char * const contact,
    const char * const reason) {}

// presence functions
void presence_subscription(const char * const jid, const jabber_subscr_t action) {}

GSList* presence_get_subscription_requests(void)
{
    return NULL;
}

gint presence_sub_request_count(void)
{
    return 0;
}

void presence_reset_sub_request_search(void) {}

char * presence_sub_request_find(char * search_str)
{
    return  NULL;
}

void presence_join_room(char *room, char *nick, char * passwd) {}
void presence_change_room_nick(const char * const room, const char * const nick) {}
void presence_leave_chat_room(const char * const room_jid) {}
void presence_update(resource_presence_t status, const char * const msg,
    int idle) {}

gboolean presence_sub_request_exists(const char * const bare_jid)
{
    return FALSE;
}

// iq functions
void iq_send_software_version(const char * const fulljid) {}
void iq_room_list_request(gchar *conferencejid) {}
void iq_disco_info_request(gchar *jid) {}
void iq_disco_items_request(gchar *jid) {}
void iq_set_autoping(int seconds) {}
void iq_confirm_instant_room(const char * const room_jid) {}
void iq_destroy_room(const char * const room_jid) {}
void iq_request_room_config_form(const char * const room_jid) {}
void iq_submit_room_config(const char * const room, DataForm *form) {}
void iq_room_config_cancel(const char * const room_jid) {}
void iq_send_ping(const char * const target) {}
void iq_send_caps_request(const char * const to, const char * const id,
    const char * const node, const char * const ver) {}
void iq_send_caps_request_for_jid(const char * const to, const char * const id,
    const char * const node, const char * const ver) {}
void iq_send_caps_request_legacy(const char * const to, const char * const id,
    const char * const node, const char * const ver) {}
void iq_room_info_request(gchar *room) {}
void iq_room_affiliation_list(const char * const room, char *affiliation) {}
void iq_room_affiliation_set(const char * const room, const char * const jid, char *affiliation,
    const char * const reason) {}
void iq_room_kick_occupant(const char * const room, const char * const nick, const char * const reason) {}
void iq_room_role_set(const char * const room, const char * const nick, char *role,
    const char * const reason) {}
void iq_room_role_list(const char * const room, char *role) {}

// caps functions
Capabilities* caps_lookup(const char * const jid)
{
    return NULL;
}

void caps_close(void) {}
void caps_destroy(Capabilities *caps) {}

gboolean bookmark_add(const char *jid, const char *nick, const char *password, const char *autojoin_str)
{
    return FALSE;
}

gboolean bookmark_update(const char *jid, const char *nick, const char *password, const char *autojoin_str)
{
    return FALSE;
}

gboolean bookmark_remove(const char *jid)
{
    return FALSE;
}

gboolean bookmark_join(const char *jid)
{
    return FALSE;
}

const GList * bookmark_get_list(void)
{
    return NULL;
}

char * bookmark_find(char *search_str)
{
    return NULL;
}

void bookmark_autocomplete_reset(void) {}

void roster_send_name_change(const char * const barejid, const char * const new_name, GSList *groups) {}
void roster_send_add_to_group(const char * const group, PContact contact) {}
void roster_send_remove_from_group(const char * const group, PContact contact) {}
void roster_send_add_new(const char * const barejid, const char * const name) {}
void roster_send_remove(const char * const barejid) {}

void form_destroy(DataForm *form) {}

char * form_get_form_type_field(DataForm *form)
{
    return NULL;
}

void form_set_value(DataForm *form, const char * const tag, char *value) {}

gboolean form_add_unique_value(DataForm *form, const char * const tag, char *value)
{
    return FALSE;
}

void form_add_value(DataForm *form, const char * const tag, char *value) {}

gboolean form_remove_value(DataForm *form, const char * const tag, char *value)
{
    return FALSE;
}

gboolean form_remove_text_multi_value(DataForm *form, const char * const tag, int index)
{
    return FALSE;
}

gboolean form_tag_exists(DataForm *form, const char * const tag)
{
    return FALSE;
}

form_field_type_t form_get_field_type(DataForm *form, const char * const tag)
{
    return FIELD_BOOLEAN;
}

gboolean form_field_contains_option(DataForm *form, const char * const tag, char *value)
{
    return FALSE;
}

int form_get_value_count(DataForm *form, const char * const tag)
{
    return 0;
}

FormField* form_get_field_by_tag(DataForm *form, const char * const tag)
{
    return NULL;
}

Autocomplete form_get_value_ac(DataForm *form, const char * const tag)
{
    return NULL;
}

void form_reset_autocompleters(DataForm *form) {}

GSList * form_get_non_form_type_fields_sorted(DataForm *form)
{
    return NULL;
}

GSList * form_get_field_values_sorted(FormField *field)
{
    return NULL;
}

