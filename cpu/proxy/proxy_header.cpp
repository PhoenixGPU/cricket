#include "proxy_header.h"

ProxyHeader::ProxyHeader(int proc_id, int device_id)
{
    this->proc_id = proc_id;
    this->device_id = device_id;
}

int ProxyHeader::get_proc_id() { return this->proc_id; }

int ProxyHeader::get_device_id() { return this->device_id; }

void ProxyHeader::set_proc_id(int proc_id) { this->proc_id = proc_id; }

void ProxyHeader::set_device_id(int device_id) { this->device_id = device_id; }