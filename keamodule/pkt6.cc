#include "keamodule.h"

using namespace std;
using namespace isc::hooks;
using namespace isc::dhcp;
using namespace isc::asiolink;

extern "C" {

static PyObject *
Pkt6_getType(Pkt6Object *self, PyObject *args) {
    try {
        uint8_t type = self->ptr->getType();
        return (PyLong_FromLong(type));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setType(Pkt6Object *self, PyObject *args) {
    unsigned char type;

    if (!PyArg_ParseTuple(args, "b", &type)) {
        return (0);
    }

    try {
        self->ptr->setType(type);
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getFlags(Pkt6Object *self, PyObject *args) {
    try {
        uint16_t flags = self->ptr->getFlags();
        return (PyLong_FromLong(flags));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setFlags(Pkt6Object *self, PyObject *args) {
    uint16_t flags;

    if (!PyArg_ParseTuple(args, "H", &flags)) {
        return (0);
    }

    try {
        self->ptr->setFlags(flags);
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getLocalAddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getLocalAddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setLocalAddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setLocalAddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getRemoteAddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getRemoteAddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setRemoteAddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setRemoteAddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getCiaddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getCiaddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setCiaddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setCiaddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getGiaddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getGiaddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setGiaddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setGiaddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getSiaddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getSiaddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setSiaddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setSiaddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getYiaddr(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->getYiaddr().toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setYiaddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        self->ptr->setYiaddr(IOAddress(string(addr)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getHWAddr(Pkt6Object *self, PyObject *args) {
    try {
        string hwaddr = self->ptr->getHWAddr()->toText(false);
        return (PyUnicode_FromString(hwaddr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_setHWAddr(Pkt6Object *self, PyObject *args) {
    char *addr;

    if (!PyArg_ParseTuple(args, "s", &addr)) {
        return (0);
    }

    try {
        HWAddr hw = HWAddr::fromText(addr);
        self->ptr->setHWAddr(HWAddrPtr(new HWAddr(hw)));
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_delOption(Pkt6Object *self, PyObject *args) {
    unsigned short type;

    if (!PyArg_ParseTuple(args, "H", &type)) {
        return (0);
    }

    try {
        bool res = self->ptr->delOption(type);
        return (PyBool_FromLong(res));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_addOption(Pkt6Object *self, PyObject *args) {
    PyObject *opt;

    if (!PyArg_ParseTuple(args, "O!", &OptionType, &opt)) {
        return (0);
    }

    try {
        self->ptr->addOption(((OptionObject *)opt)->ptr);
        Py_INCREF(self);
        return ((PyObject *)self);
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_getOption(Pkt6Object *self, PyObject *args) {
    unsigned short type;

    if (!PyArg_ParseTuple(args, "H", &type)) {
        return (0);
    }

    try {
        OptionPtr ptr = self->ptr->getOption(type);
        if (!ptr) {
            Py_RETURN_NONE;
        }
        return (Option_from_handle(ptr));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_toText(Pkt6Object *self, PyObject *args) {
    try {
        string addr = self->ptr->toText();
        return (PyUnicode_FromString(addr.c_str()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_pack(Pkt6Object *self, PyObject *args) {
    try {
        self->ptr->pack();
        return (PyBytes_FromStringAndSize((char *)self->ptr->getBuffer().getData(), self->ptr->getBuffer().getLength()));
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyObject *
Pkt6_unpack(Pkt6Object *self, PyObject *args) {
    try {
        self->ptr->unpack();
        Py_RETURN_NONE;
    }
    catch (const exception &e) {
        PyErr_SetString(PyExc_TypeError, e.what());
        return (0);
    }
}

static PyMethodDef Pkt6_methods[] = {
    {"getType", (PyCFunction) Pkt6_getType, METH_NOARGS,
     "For packets without DHCP Message Type option, it returns DHCP_NOTYPE (0)."},
    {"setType", (PyCFunction) Pkt6_setType, METH_VARARGS,
     "Sets DHCP message type."},
    {"getFlags", (PyCFunction) Pkt6_getFlags, METH_NOARGS,
     "Returns flags field."},
    {"setFlags", (PyCFunction) Pkt6_setFlags, METH_VARARGS,
     "Sets flags field."},
    {"getLocalAddr", (PyCFunction) Pkt6_getLocalAddr, METH_NOARGS,
     "Returns local IP address."},
    {"setLocalAddr", (PyCFunction) Pkt6_setLocalAddr, METH_VARARGS,
     "Sets local IP address."},
    {"getRemoteAddr", (PyCFunction) Pkt6_getRemoteAddr, METH_NOARGS,
     "Returns remote IP address."},
    {"setRemoteAddr", (PyCFunction) Pkt6_setRemoteAddr, METH_VARARGS,
     "Sets remote IP address."},
    {"getCiaddr", (PyCFunction) Pkt6_getCiaddr, METH_NOARGS,
     "Returns ciaddr field."},
    {"setCiaddr", (PyCFunction) Pkt6_setCiaddr, METH_VARARGS,
     "Sets ciaddr field."},
    {"getGiaddr", (PyCFunction) Pkt6_getGiaddr, METH_NOARGS,
     "Returns giaddr field."},
    {"setGiaddr", (PyCFunction) Pkt6_setGiaddr, METH_VARARGS,
     "Sets giaddr field."},
    {"getSiaddr", (PyCFunction) Pkt6_getSiaddr, METH_NOARGS,
     "Returns siaddr field."},
    {"setSiaddr", (PyCFunction) Pkt6_setSiaddr, METH_VARARGS,
     "Sets siaddr field."},
    {"getYiaddr", (PyCFunction) Pkt6_getYiaddr, METH_NOARGS,
     "Returns yiaddr field."},
    {"setYiaddr", (PyCFunction) Pkt6_setYiaddr, METH_VARARGS,
     "Sets yiaddr field."},
    {"getHWAddr", (PyCFunction) Pkt6_getHWAddr, METH_NOARGS,
     "Returns hardware address."},
    {"setHWAddr", (PyCFunction) Pkt6_setHWAddr, METH_VARARGS,
     "Sets hardware address."},
    {"delOption", (PyCFunction) Pkt6_delOption, METH_VARARGS,
     "Attempts to delete first suboption of requested type."},
    {"addOption", (PyCFunction) Pkt6_addOption, METH_VARARGS,
     "Adds an option to this packet."},
    {"getOption", (PyCFunction) Pkt6_getOption, METH_VARARGS,
     "Returns the first option of specified type."},
    {"toText", (PyCFunction) Pkt6_toText, METH_NOARGS,
     "Returns text representation of the packet."},
    {"pack", (PyCFunction) Pkt6_pack, METH_NOARGS,
     "Prepares on-wire format of DHCPv6 packet."},
    {"unpack", (PyCFunction) Pkt6_unpack, METH_NOARGS,
     "Parses on-wire form of DHCPv6 packet."},
    {0}  // Sentinel
};

static PyObject *
Pkt6_use_count(Pkt6Object *self, void *closure) {
    return (PyLong_FromLong(self->ptr.use_count()));
}

static PyGetSetDef Pkt6_getsetters[] = {
    {(char *)"use_count", (getter) Pkt6_use_count, (setter) 0, (char *)"shared_ptr use count", 0},
    {0}  // Sentinel
};

static void
Pkt6_dealloc(Pkt6Object *self) {
    self->ptr.~Pkt6Ptr();
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static int
Pkt6_init(Pkt6Object *self, PyObject *args, PyObject *kwds) {
    unsigned char msg_type;
    unsigned long transid;
    PyObject *data;

    new(&self->ptr) Pkt6Ptr;

    if (kwds != 0) {
        PyErr_SetString(PyExc_TypeError, "keyword arguments are not supported");
        return (-1);
    }

    if (PyTuple_Size(args) == 1) {
        if (!PyArg_ParseTuple(args, "S", &data)) {
            return (-1);
        }
        uint8_t *buff;
        Py_ssize_t len;
        PyBytes_AsStringAndSize(data, (char**)&buff, &len);

        self->ptr.reset(new Pkt6(buff, len));
    }
    else {
        if (!PyArg_ParseTuple(args, "bk", &msg_type, &transid)) {
            return (-1);
        }

        self->ptr.reset(new Pkt6(msg_type, transid));
    }

    return (0);
}

static PyObject *
Pkt6_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    Pkt6Object *self;
    self = (Pkt6Object *) type->tp_alloc(type, 0);
    if (self) {
        new(&self->ptr) Pkt6Ptr;
    }
    return ((PyObject *) self);
}

PyTypeObject Pkt6Type = {
    PyObject_HEAD_INIT(0)
    "kea.Pkt6",                                 // tp_name
    sizeof(Pkt6Object),                         // tp_basicsize
    0,                                          // tp_itemsize
    (destructor) Pkt6_dealloc,                  // tp_dealloc
    0,                                          // tp_vectorcall_offset
    0,                                          // tp_getattr
    0,                                          // tp_setattr
    0,                                          // tp_as_async
    0,                                          // tp_repr
    0,                                          // tp_as_number
    0,                                          // tp_as_sequence
    0,                                          // tp_as_mapping
    0,                                          // tp_hash
    0,                                          // tp_call
    0,                                          // tp_str
    0,                                          // tp_getattro
    0,                                          // tp_setattro
    0,                                          // tp_as_buffer
    Py_TPFLAGS_DEFAULT,                         // tp_flags
    "Kea server Pkt6",                          // tp_doc
    0,                                          // tp_traverse
    0,                                          // tp_clear
    0,                                          // tp_richcompare
    0,                                          // tp_weaklistoffset
    0,                                          // tp_iter
    0,                                          // tp_iternext
    Pkt6_methods,                               // tp_methods
    0,                                          // tp_members
    Pkt6_getsetters,                            // tp_getset
    0,                                          // tp_base
    0,                                          // tp_dict
    0,                                          // tp_descr_get
    0,                                          // tp_descr_set
    0,                                          // tp_dictoffset
    (initproc) Pkt6_init,                       // tp_init
    PyType_GenericAlloc,                        // tp_alloc
    Pkt6_new                                    // tp_new
};

PyObject *
Pkt6_from_handle(Pkt6Ptr &ptr) {
    Pkt6Object *self = PyObject_New(Pkt6Object, &Pkt6Type);
    if (self) {
        new(&self->ptr) Pkt6Ptr;
        self->ptr = ptr;
    }
    return (PyObject *)self;
}

int
Pkt6_define() {
    if (PyType_Ready(&Pkt6Type) < 0) {
        return (1);
    }
    Py_INCREF(&Pkt6Type);
    if (PyModule_AddObject(kea_module, "Pkt6", (PyObject *) &Pkt6Type) < 0) {
        Py_DECREF(&Pkt6Type);
        return (1);
    }

    return (0);
}

}
