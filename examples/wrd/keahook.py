from kea import *
from ipaddress import IPv6Address

def pkt6_send(handle):
    response = handle.getArgument('response6')

    servers = [IPv6Address('2000::1'), IPv6Address('2000::2')]
    packed_servers = b''.join([addr.packed for addr in servers])

    response.addOption(Option(D6O_NAME_SERVERS).setBytes(packed_servers))
    response.addOption(Option(32).setUint16(8000))

    return 0
