// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Atcommands
 * Place the body of custom atcommands in this file.
 * Format:
 *	ACMD_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//ACMD_FUNC(newcommand)
//{
//	clif_displaymessage(fd, "It works!");
//	clif_specialeffect(&sd->bl, 343, AREA);
//	return 0;
//}

/**  
* Fake players online in game  
* Usage: @fakeuser <number>  
*/  
ACMD_FUNC(fakeuser) {  
	int num = 0;  
  
	memset(atcmd_output, '\0', sizeof(atcmd_output));  
  
	if (!message || !*message || sscanf(message, "%d", &num) < 1) {  
		sprintf(atcmd_output, "Usage: @fakeuser <number>.");  
		clif_displaymessage(fd, atcmd_output);  
		return -1;  
	}  
  
	fake_users += num;  
  
	if (fake_users < 0)  
		fake_users = 0;  
  
	return 0;
}

/*==========================================
* @oninit by [tr0n]
*------------------------------------------*/
ACMD_FUNC(oninit)
{
	char label_output[CHAT_SIZE_MAX];

	nullpo_retr(-1, sd);
	
	if (!message || !*message) {
		sprintf(atcmd_output, "Please enter <npc name>");
		clif_displaymessage(fd, atcmd_output);
		return -1;
	}

	if (npc_name2id(message) != NULL) {
		sprintf(label_output, "%s::OnInit", message);
		npc_event( sd, label_output, 0 );
		clif_displaymessage(fd, "OnInit was triggered.");
		return 0;
	}
	else {
		clif_displaymessage(fd, "NPC doesn't exist.");
		return -1;
	}
}