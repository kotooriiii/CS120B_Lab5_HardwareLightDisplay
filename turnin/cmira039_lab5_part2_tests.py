tests = [ 
	{
		'description': 'PINA: 0x01, 0x00, 0x01 => PORTC: 0x00',
		'steps': [
			{'inputs': [('PINA', 0xFE)], 'iterations': 2},
			{'inputs': [('PINA', 0xFF)], 'iterations': 2},
			{'inputs': [('PINA', 0xFE)], 'iterations': 2}
			],
		'expected': [('PORTC',0x00)],
    },
	{
		'description': 'PINA: 0x03, 0x01, 0x02=> PORTC: 0x00',
		'steps':
			[
			{'inputs': [('PINA', 0xFC)], 'iterations': 2},
			{'inputs': [('PINA', 0xFE)], 'iterations': 2},
			{'inputs': [('PINA', 0xFD)], 'iterations': 2}
			],
		'expected': [('PORTC',0x00)],
    },
	{'description': 'PINA: 0x02, 0x03=> PORTC: 0x00',
    'steps': [
		{'inputs': [('PINA', 0xFD)], 'iterations': 2},
        {'inputs': [('PINA', 0xFC)], 'iterations': 2}],
    'expected': [('PORTC',0x00)],
    },
    ]
	
