
unsigned char error_status;
unsigned char perr_status;

void add_error(char no)
{
	error_status |= (1<<no);
}

void remove_error(char no)
{
	error_status &= ~(1<<no);
}
