tests = [ 
	{
		'description': 'PINA: 0x01, 0x00, 0x01 => PORTB: 0x02',
		'steps': [
			{'inputs': [('PINA', 0x01)], 'iterations': 2},
			{'inputs': [('PINA', 0x00)], 'iterations': 2},
			{'inputs': [('PINA', 0x01)], 'iterations': 2}
			],
		'expected': [('PORTB',0x02)],
    },
	{
		'description': 'PINA: 0x01, 0x01, 0x01 => PORTB: 0x01',
		'steps':
			[
			{'inputs': [('PINA', 0x01)], 'iterations': 2},
			{'inputs': [('PINA', 0x01)], 'iterations': 2},
			{'inputs': [('PINA', 0x01)], 'iterations': 2}
			],
		'expected': [('PORTC',0x01)],
    },
    ]
	
