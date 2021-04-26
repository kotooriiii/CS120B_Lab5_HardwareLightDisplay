tests = [ {'description': 'First test. Testing example 1',
    'steps': [ {'inputs': [('PINA',0xFC)], 'iterations': 5 } ],
    'expected': [('PORTC',0x70)],
    },
    {'description': 'Second test. Testing example 2',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x40)],
    },
    {'description': 'Third test. Testing example 3',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3F)],
    },
    ]
#watch = ['PORTB']

